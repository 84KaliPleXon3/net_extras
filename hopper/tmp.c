#include "netlink/netlink.h"
#include "netlink/genl/genl.h"
#include "netlink/genl/ctrl.h"
#include <net/if.h>

#include "nl80211.h"

static int expectedId;

static int nlCallback(struct nl_msg* msg, void* arg)
{
    struct nlmsghdr* ret_hdr = nlmsg_hdr(msg);
    struct nlattr *tb_msg[NL80211_ATTR_MAX + 1];

    if (ret_hdr->nlmsg_type != expectedId)
    {
        // what is this??
        return NL_STOP;
    }

    struct genlmsghdr *gnlh = (struct genlmsghdr*) nlmsg_data(ret_hdr);

    nla_parse(tb_msg, NL80211_ATTR_MAX, genlmsg_attrdata(gnlh, 0),
              genlmsg_attrlen(gnlh, 0), NULL);

    if (tb_msg[NL80211_ATTR_IFTYPE]) {
        int type = nla_get_u32(tb_msg[NL80211_ATTR_IFTYPE]);

        printf("Type: %i\n", type);
    }
}

int main(int argc, char** argv)
{
    int ret;
    //allocate socket
    struct nl_sock* sk = nl_socket_alloc();

    //connect to generic netlink
    genl_connect(sk);

    //find the nl80211 driver ID
    expectedId = genl_ctrl_resolve(sk, "nl80211");

    //attach a callback
    nl_socket_modify_cb(sk, NL_CB_VALID, NL_CB_CUSTOM,
            nlCallback, NULL);

    //allocate a message
    struct nl_msg* msg = nlmsg_alloc();

    const enum nl80211_commands cmd = NL80211_CMD_GET_INTERFACE;
    int ifIndex = if_nametoindex("wlp4s0");
    int flags = 0;

    // setup the message
    genlmsg_put(msg, 0, 0, expectedId, 0, flags, cmd, 0);

    //add message attributes
    NLA_PUT_U32(msg, NL80211_ATTR_IFINDEX, ifIndex);

    //send the messge (this frees it)
    ret = nl_send_auto_complete(sk, msg);

    //block for message to return
    nl_recvmsgs_default(sk);

    return 0;

nla_put_failure:
    nlmsg_free(msg);
    return 1;
}
