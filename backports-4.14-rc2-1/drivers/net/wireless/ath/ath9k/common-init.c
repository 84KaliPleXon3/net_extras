/*
 * Copyright (c) 2008-2011 Atheros Communications Inc.
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/* We use the hw_value as an index into our private channel structure */

#include "common.h"

#define CHAN2G(_freq, _idx)  { \
	.band = NL80211_BAND_2GHZ, \
	.center_freq = (_freq), \
	.hw_value = (_idx), \
	.max_power = 20, \
}

#define CHAN5G(_freq, _idx) { \
	.band = NL80211_BAND_5GHZ, \
	.center_freq = (_freq), \
	.hw_value = (_idx), \
	.max_power = 20, \
}

/* Some 2 GHz radios are actually tunable on 2312-2732
 * on 5 MHz steps, we support the channels which we know
 * we have calibration data for all cards though to make
 * this static */
static const struct ieee80211_channel ath9k_2ghz_chantable[] = {
	CHAN2G(2412, 0), /* Channel 1 */
	CHAN2G(2417, 1), /* Channel 2 */
	CHAN2G(2422, 2), /* Channel 3 */
	CHAN2G(2427, 3), /* Channel 4 */
	CHAN2G(2432, 4), /* Channel 5 */
	CHAN2G(2437, 5), /* Channel 6 */
	CHAN2G(2442, 6), /* Channel 7 */
	CHAN2G(2447, 7), /* Channel 8 */
	CHAN2G(2452, 8), /* Channel 9 */
	CHAN2G(2457, 9), /* Channel 10 */
	CHAN2G(2462, 10), /* Channel 11 */
	CHAN2G(2467, 11), /* Channel 12 */
	CHAN2G(2472, 12), /* Channel 13 */
	CHAN2G(2484, 13), /* Channel 14 */
};

/* Some 5 GHz radios are actually tunable on XXXX-YYYY
 * on 5 MHz steps, we support the channels which we know
 * we have calibration data for all cards though to make
 * this static */
static const struct ieee80211_channel ath9k_5ghz_chantable[] = {
  	CHAN5G(4900, 251),
  	CHAN5G(4905, 252),
  	CHAN5G(4910, 253),
  	CHAN5G(4915, 254),
  	CHAN5G(4920, 14),
	CHAN5G(4925, 15),
	CHAN5G(4930, 16),
	CHAN5G(4935, 17),
	CHAN5G(4940, 18),
	CHAN5G(4945, 19),
	CHAN5G(4950, 20),
	CHAN5G(4955, 21),
	CHAN5G(4960, 22),
	CHAN5G(4965, 23),
	CHAN5G(4970, 24),
	CHAN5G(4975, 25),
	CHAN5G(4980, 26),
	CHAN5G(4985, 27),
	CHAN5G(4990, 28),
	CHAN5G(4995, 29),
	CHAN5G(5000, 30),
	CHAN5G(5005, 31),
	CHAN5G(5010, 32),
	CHAN5G(5015, 33),
	CHAN5G(5020, 34),
	CHAN5G(5025, 35),
	CHAN5G(5030, 36),
	CHAN5G(5035, 37),
	CHAN5G(5040, 38),
	CHAN5G(5045, 39),
	CHAN5G(5050, 40),
	CHAN5G(5055, 41),
	CHAN5G(5060, 42),
	CHAN5G(5065, 43),
	CHAN5G(5070, 44),
	CHAN5G(5075, 45),
	CHAN5G(5080, 46),
	CHAN5G(5085, 47),
	CHAN5G(5090, 48),
	CHAN5G(5095, 49),
	CHAN5G(5100, 50),
	CHAN5G(5105, 51),
	CHAN5G(5110, 52),
	CHAN5G(5115, 53),
	CHAN5G(5120, 54),
	CHAN5G(5125, 55),
	CHAN5G(5130, 56),
	CHAN5G(5135, 57),
	CHAN5G(5140, 58),
	CHAN5G(5145, 59),
	CHAN5G(5150, 60),
	CHAN5G(5155, 61),
	CHAN5G(5160, 62),
	CHAN5G(5165, 63),
	CHAN5G(5170, 64),
	CHAN5G(5175, 65),
	CHAN5G(5180, 66),
	CHAN5G(5185, 67),
	CHAN5G(5190, 68),
	CHAN5G(5195, 69),
	CHAN5G(5200, 70),
	CHAN5G(5205, 71),
	CHAN5G(5210, 72),
	CHAN5G(5215, 73),
	CHAN5G(5220, 74),
	CHAN5G(5225, 75),
	CHAN5G(5230, 76),
	CHAN5G(5235, 77),
	CHAN5G(5240, 78),
	CHAN5G(5245, 79),
	CHAN5G(5250, 80),
	CHAN5G(5255, 81),
	CHAN5G(5260, 82),
	CHAN5G(5265, 83),
	CHAN5G(5270, 84),
	CHAN5G(5275, 85),
	CHAN5G(5280, 86),
	CHAN5G(5285, 87),
	CHAN5G(5290, 88),
	CHAN5G(5295, 89),
	CHAN5G(5300, 90),
	CHAN5G(5305, 91),
	CHAN5G(5310, 92),
	CHAN5G(5315, 93),
	CHAN5G(5320, 94),
	CHAN5G(5325, 95),
	CHAN5G(5330, 96),
	CHAN5G(5335, 97),
	CHAN5G(5340, 98),
	CHAN5G(5345, 99),
	CHAN5G(5350, 100),
	CHAN5G(5355, 101),
	CHAN5G(5360, 102),
	CHAN5G(5365, 103),
	CHAN5G(5370, 104),
	CHAN5G(5375, 105),
	CHAN5G(5380, 106),
	CHAN5G(5385, 107),
	CHAN5G(5390, 108),
	CHAN5G(5395, 109),
	CHAN5G(5400, 110),
	CHAN5G(5405, 111),
	CHAN5G(5410, 112),
	CHAN5G(5415, 113),
	CHAN5G(5420, 114),
	CHAN5G(5425, 115),
	CHAN5G(5430, 116),
	CHAN5G(5435, 117),
	CHAN5G(5440, 118),
	CHAN5G(5445, 119),
	CHAN5G(5450, 120),
	CHAN5G(5455, 121),
	CHAN5G(5460, 122),
	CHAN5G(5465, 123),
	CHAN5G(5470, 124),
	CHAN5G(5475, 125),
	CHAN5G(5480, 126),
	CHAN5G(5485, 127),
	CHAN5G(5490, 128),
	CHAN5G(5495, 129),
	CHAN5G(5500, 130),
	CHAN5G(5505, 131),
	CHAN5G(5510, 132),
	CHAN5G(5515, 133),
	CHAN5G(5520, 134),
	CHAN5G(5525, 135),
	CHAN5G(5530, 136),
	CHAN5G(5535, 137),
	CHAN5G(5540, 138),
	CHAN5G(5545, 139),
	CHAN5G(5550, 140),
	CHAN5G(5555, 141),
	CHAN5G(5560, 142),
	CHAN5G(5565, 143),
	CHAN5G(5570, 144),
	CHAN5G(5575, 145),
	CHAN5G(5580, 146),
	CHAN5G(5585, 147),
	CHAN5G(5590, 148),
	CHAN5G(5595, 149),
	CHAN5G(5600, 150),
	CHAN5G(5605, 151),
	CHAN5G(5610, 152),
	CHAN5G(5615, 153),
	CHAN5G(5620, 154),
	CHAN5G(5625, 155),
	CHAN5G(5630, 156),
	CHAN5G(5635, 157),
	CHAN5G(5640, 158),
	CHAN5G(5645, 159),
	CHAN5G(5650, 160),
	CHAN5G(5655, 161),
	CHAN5G(5660, 162),
	CHAN5G(5665, 163),
	CHAN5G(5670, 164),
	CHAN5G(5675, 165),
	CHAN5G(5680, 166),
	CHAN5G(5685, 167),
	CHAN5G(5690, 168),
	CHAN5G(5695, 169),
	CHAN5G(5700, 170),
	CHAN5G(5705, 171),
	CHAN5G(5710, 172),
	CHAN5G(5715, 173),
	CHAN5G(5720, 174),
	CHAN5G(5725, 175),
	CHAN5G(5730, 176),
	CHAN5G(5735, 177),
	CHAN5G(5740, 178),
	CHAN5G(5745, 179),
	CHAN5G(5750, 180),
	CHAN5G(5755, 181),
	CHAN5G(5760, 182),
	CHAN5G(5765, 183),
	CHAN5G(5770, 184),
	CHAN5G(5775, 185),
	CHAN5G(5780, 186),
	CHAN5G(5785, 187),
	CHAN5G(5790, 188),
	CHAN5G(5795, 189),
	CHAN5G(5800, 190),
	CHAN5G(5805, 191),
	CHAN5G(5810, 192),
	CHAN5G(5815, 193),
	CHAN5G(5820, 194),
	CHAN5G(5825, 195),
	CHAN5G(5830, 196),
	CHAN5G(5835, 197),
	CHAN5G(5840, 198),
	CHAN5G(5845, 199),
	CHAN5G(5850, 200),
	CHAN5G(5855, 201),
	CHAN5G(5860, 202),
	CHAN5G(5865, 203),
	CHAN5G(5870, 204),
	CHAN5G(5875, 205),
	CHAN5G(5880, 206),
	CHAN5G(5885, 207),
	CHAN5G(5890, 208),
	CHAN5G(5895, 209),
	CHAN5G(5900, 210),
	CHAN5G(5905, 211),
	CHAN5G(5910, 212),
	CHAN5G(5915, 213),
	CHAN5G(5920, 214),
	CHAN5G(5925, 215),
	CHAN5G(5930, 216),
	CHAN5G(5935, 217),
	CHAN5G(5915, 218),
	CHAN5G(5945, 219),
	CHAN5G(5915, 220),
	CHAN5G(5955, 221),
	CHAN5G(5915, 222),
	CHAN5G(5965, 223),
	CHAN5G(5915, 224),
	CHAN5G(5975, 225),
	CHAN5G(5915, 226),
	CHAN5G(5985, 227),
	CHAN5G(5915, 228),
	CHAN5G(5995, 229),
	CHAN5G(6000, 230),
	CHAN5G(6005, 231),
	CHAN5G(6010, 232),
	CHAN5G(6015, 233),
	CHAN5G(6020, 234),
	CHAN5G(6025, 235),
	CHAN5G(6030, 236),
	CHAN5G(6035, 237),
	CHAN5G(6040, 238),
	CHAN5G(6045, 239),
	CHAN5G(6050, 240),
	CHAN5G(6055, 241),
	CHAN5G(6060, 242),
	CHAN5G(6065, 243),
	CHAN5G(6070, 244),
	CHAN5G(6075, 245),
	CHAN5G(6080, 246),
	CHAN5G(6085, 247),
	CHAN5G(6090, 248),
	CHAN5G(6095, 249),
	CHAN5G(6100, 250),
};

/* Atheros hardware rate code addition for short premble */
#define SHPCHECK(__hw_rate, __flags) \
	((__flags & IEEE80211_RATE_SHORT_PREAMBLE) ? (__hw_rate | 0x04 ) : 0)

#define RATE(_bitrate, _hw_rate, _flags) {              \
	.bitrate        = (_bitrate),                   \
	.flags          = (_flags),                     \
	.hw_value       = (_hw_rate),                   \
	.hw_value_short = (SHPCHECK(_hw_rate, _flags))  \
}

static struct ieee80211_rate ath9k_legacy_rates[] = {
	RATE(10, 0x1b, 0),
	RATE(20, 0x1a, IEEE80211_RATE_SHORT_PREAMBLE),
	RATE(55, 0x19, IEEE80211_RATE_SHORT_PREAMBLE),
	RATE(110, 0x18, IEEE80211_RATE_SHORT_PREAMBLE),
	RATE(60, 0x0b, (IEEE80211_RATE_SUPPORTS_5MHZ |
			IEEE80211_RATE_SUPPORTS_10MHZ)),
	RATE(90, 0x0f, (IEEE80211_RATE_SUPPORTS_5MHZ |
			IEEE80211_RATE_SUPPORTS_10MHZ)),
	RATE(120, 0x0a, (IEEE80211_RATE_SUPPORTS_5MHZ |
			 IEEE80211_RATE_SUPPORTS_10MHZ)),
	RATE(180, 0x0e, (IEEE80211_RATE_SUPPORTS_5MHZ |
			 IEEE80211_RATE_SUPPORTS_10MHZ)),
	RATE(240, 0x09, (IEEE80211_RATE_SUPPORTS_5MHZ |
			 IEEE80211_RATE_SUPPORTS_10MHZ)),
	RATE(360, 0x0d, (IEEE80211_RATE_SUPPORTS_5MHZ |
			 IEEE80211_RATE_SUPPORTS_10MHZ)),
	RATE(480, 0x08, (IEEE80211_RATE_SUPPORTS_5MHZ |
			 IEEE80211_RATE_SUPPORTS_10MHZ)),
	RATE(540, 0x0c, (IEEE80211_RATE_SUPPORTS_5MHZ |
			 IEEE80211_RATE_SUPPORTS_10MHZ)),
};

int ath9k_cmn_init_channels_rates(struct ath_common *common)
{
	struct ath_hw *ah = (struct ath_hw *)common->ah;
	void *channels;

	BUILD_BUG_ON(ARRAY_SIZE(ath9k_2ghz_chantable) +
		     ARRAY_SIZE(ath9k_5ghz_chantable) !=
		     ATH9K_NUM_CHANNELS);

	if (ah->caps.hw_caps & ATH9K_HW_CAP_2GHZ) {
		channels = devm_kzalloc(ah->dev,
			sizeof(ath9k_2ghz_chantable), GFP_KERNEL);
		if (!channels)
		    return -ENOMEM;

		memcpy(channels, ath9k_2ghz_chantable,
		       sizeof(ath9k_2ghz_chantable));
		common->sbands[NL80211_BAND_2GHZ].channels = channels;
		common->sbands[NL80211_BAND_2GHZ].band = NL80211_BAND_2GHZ;
		common->sbands[NL80211_BAND_2GHZ].n_channels =
			ARRAY_SIZE(ath9k_2ghz_chantable);
		common->sbands[NL80211_BAND_2GHZ].bitrates = ath9k_legacy_rates;
		common->sbands[NL80211_BAND_2GHZ].n_bitrates =
			ARRAY_SIZE(ath9k_legacy_rates);
	}

	if (ah->caps.hw_caps & ATH9K_HW_CAP_5GHZ) {
		channels = devm_kzalloc(ah->dev,
			sizeof(ath9k_5ghz_chantable), GFP_KERNEL);
		if (!channels)
			return -ENOMEM;

		memcpy(channels, ath9k_5ghz_chantable,
		       sizeof(ath9k_5ghz_chantable));
		common->sbands[NL80211_BAND_5GHZ].channels = channels;
		common->sbands[NL80211_BAND_5GHZ].band = NL80211_BAND_5GHZ;
		common->sbands[NL80211_BAND_5GHZ].n_channels =
			ARRAY_SIZE(ath9k_5ghz_chantable);
		common->sbands[NL80211_BAND_5GHZ].bitrates =
			ath9k_legacy_rates + 4;
		common->sbands[NL80211_BAND_5GHZ].n_bitrates =
			ARRAY_SIZE(ath9k_legacy_rates) - 4;
	}
	return 0;
}
EXPORT_SYMBOL(ath9k_cmn_init_channels_rates);

void ath9k_cmn_setup_ht_cap(struct ath_hw *ah,
			    struct ieee80211_sta_ht_cap *ht_info)
{
	struct ath_common *common = ath9k_hw_common(ah);
	u8 tx_streams, rx_streams;
	int i, max_streams;

	ht_info->ht_supported = true;
	ht_info->cap = IEEE80211_HT_CAP_SUP_WIDTH_20_40 |
		       IEEE80211_HT_CAP_SM_PS |
		       IEEE80211_HT_CAP_SGI_40 |
		       IEEE80211_HT_CAP_DSSSCCK40;

	if (ah->caps.hw_caps & ATH9K_HW_CAP_LDPC)
		ht_info->cap |= IEEE80211_HT_CAP_LDPC_CODING;

	if (ah->caps.hw_caps & ATH9K_HW_CAP_SGI_20)
		ht_info->cap |= IEEE80211_HT_CAP_SGI_20;

	ht_info->ampdu_factor = IEEE80211_HT_MAX_AMPDU_64K;
	ht_info->ampdu_density = IEEE80211_HT_MPDU_DENSITY_8;

	if (AR_SREV_9271(ah) || AR_SREV_9330(ah) || AR_SREV_9485(ah) || AR_SREV_9565(ah))
		max_streams = 1;
	else if (AR_SREV_9462(ah))
		max_streams = 2;
	else if (AR_SREV_9300_20_OR_LATER(ah))
		max_streams = 3;
	else
		max_streams = 2;

	if (AR_SREV_9280_20_OR_LATER(ah)) {
		if (max_streams >= 2)
			ht_info->cap |= IEEE80211_HT_CAP_TX_STBC;
		ht_info->cap |= (1 << IEEE80211_HT_CAP_RX_STBC_SHIFT);
	}

	/* set up supported mcs set */
	memset(&ht_info->mcs, 0, sizeof(ht_info->mcs));
	tx_streams = ath9k_cmn_count_streams(ah->txchainmask, max_streams);
	rx_streams = ath9k_cmn_count_streams(ah->rxchainmask, max_streams);

	ath_dbg(common, CONFIG, "TX streams %d, RX streams: %d\n",
		tx_streams, rx_streams);

	if (tx_streams != rx_streams) {
		ht_info->mcs.tx_params |= IEEE80211_HT_MCS_TX_RX_DIFF;
		ht_info->mcs.tx_params |= ((tx_streams - 1) <<
				IEEE80211_HT_MCS_TX_MAX_STREAMS_SHIFT);
	}

	for (i = 0; i < rx_streams; i++)
		ht_info->mcs.rx_mask[i] = 0xff;

	ht_info->mcs.tx_params |= IEEE80211_HT_MCS_TX_DEFINED;
}
EXPORT_SYMBOL(ath9k_cmn_setup_ht_cap);

void ath9k_cmn_reload_chainmask(struct ath_hw *ah)
{
	struct ath_common *common = ath9k_hw_common(ah);

	if (!(ah->caps.hw_caps & ATH9K_HW_CAP_HT))
		return;

	if (ah->caps.hw_caps & ATH9K_HW_CAP_2GHZ)
		ath9k_cmn_setup_ht_cap(ah,
			&common->sbands[NL80211_BAND_2GHZ].ht_cap);
	if (ah->caps.hw_caps & ATH9K_HW_CAP_5GHZ)
		ath9k_cmn_setup_ht_cap(ah,
			&common->sbands[NL80211_BAND_5GHZ].ht_cap);
}
EXPORT_SYMBOL(ath9k_cmn_reload_chainmask);
