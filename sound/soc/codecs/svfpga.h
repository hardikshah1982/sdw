/*
 * svfpga.h -- SVFPGA ALSA SoC audio driver header
 *
 * Copyright 2015 Intel, Inc.
 *
 * Author: Hardik Shah <hardik.t.shah@intel.com>
 * Dummy ASoC Codec Driver based Cirrus Logic CS42L42 Codec
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#ifndef __SVFPGA_H__
#define __SVFPGA_H__

#include <linux/regulator/consumer.h>

struct  svfpga_private {
	struct regmap *regmap;
	struct snd_soc_codec *codec;
	struct regulator_bulk_data supplies[SVFPGA_NUM_SUPPLIES];
	struct gpio_desc *reset_gpio;
	u32 sclk;
	u8 hpout_load;
	u8 hpout_clamp;
	struct sdw_slave *sdw;
};

int svfpga_probe(struct device *dev, struct regmap *regmap,
					struct sdw_slave *slave);
int svfpga_remove(struct device *dev);
#endif /* __SVFPGA_H__ */
