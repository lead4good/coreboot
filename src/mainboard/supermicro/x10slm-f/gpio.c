/* SPDX-License-Identifier: GPL-2.0-or-later */

#include <southbridge/intel/common/gpio.h>

static const struct pch_gpio_set1 pch_gpio_set1_mode = {
	.gpio0 = GPIO_MODE_GPIO,
	.gpio1 = GPIO_MODE_GPIO,
	.gpio2 = GPIO_MODE_GPIO,
	.gpio3 = GPIO_MODE_GPIO,
	.gpio4 = GPIO_MODE_GPIO,
	.gpio5 = GPIO_MODE_GPIO,
	.gpio6 = GPIO_MODE_GPIO,
	.gpio7 = GPIO_MODE_GPIO,
	.gpio8 = GPIO_MODE_GPIO,
	.gpio9 = GPIO_MODE_GPIO,
	.gpio10 = GPIO_MODE_GPIO,
	.gpio13 = GPIO_MODE_GPIO,
	.gpio14 = GPIO_MODE_GPIO,
	.gpio15 = GPIO_MODE_GPIO,
	.gpio16 = GPIO_MODE_GPIO,
	.gpio17 = GPIO_MODE_GPIO,
	.gpio19 = GPIO_MODE_GPIO,
	.gpio20 = GPIO_MODE_GPIO,
	.gpio21 = GPIO_MODE_GPIO,
	.gpio24 = GPIO_MODE_GPIO,
	.gpio25 = GPIO_MODE_GPIO,
	.gpio26 = GPIO_MODE_GPIO,
	.gpio27 = GPIO_MODE_GPIO,
	.gpio28 = GPIO_MODE_GPIO,
	.gpio29 = GPIO_MODE_GPIO,
};

static const struct pch_gpio_set1 pch_gpio_set1_direction = {
	.gpio0 = GPIO_DIR_OUTPUT,
	.gpio1 = GPIO_DIR_OUTPUT,
	.gpio2 = GPIO_DIR_OUTPUT,
	.gpio3 = GPIO_DIR_INPUT,
	.gpio4 = GPIO_DIR_INPUT,
	.gpio5 = GPIO_DIR_INPUT,
	.gpio6 = GPIO_DIR_OUTPUT,
	.gpio7 = GPIO_DIR_OUTPUT,
	.gpio8 = GPIO_DIR_OUTPUT,
	.gpio9 = GPIO_DIR_INPUT,
	.gpio10 = GPIO_DIR_INPUT,
	.gpio13 = GPIO_DIR_INPUT,
	.gpio14 = GPIO_DIR_INPUT,
	.gpio15 = GPIO_DIR_INPUT,
	.gpio16 = GPIO_DIR_OUTPUT,
	.gpio17 = GPIO_DIR_INPUT,
	.gpio19 = GPIO_DIR_OUTPUT,
	.gpio20 = GPIO_DIR_OUTPUT,
	.gpio21 = GPIO_DIR_INPUT,
	.gpio24 = GPIO_DIR_OUTPUT,
	.gpio25 = GPIO_DIR_INPUT,
	.gpio26 = GPIO_DIR_INPUT,
	.gpio27 = GPIO_DIR_OUTPUT,
	.gpio28 = GPIO_DIR_OUTPUT,
	.gpio29 = GPIO_DIR_INPUT,
};

static const struct pch_gpio_set1 pch_gpio_set1_level = {
	.gpio0 = GPIO_LEVEL_HIGH,
	.gpio1 = GPIO_LEVEL_HIGH,
	.gpio2 = GPIO_LEVEL_HIGH,
	.gpio6 = GPIO_LEVEL_HIGH,
	.gpio7 = GPIO_LEVEL_HIGH,
	.gpio8 = GPIO_LEVEL_HIGH,
	.gpio16 = GPIO_LEVEL_HIGH,
	.gpio19 = GPIO_LEVEL_HIGH,
	.gpio20 = GPIO_LEVEL_HIGH,
	.gpio24 = GPIO_LEVEL_HIGH,
	.gpio27 = GPIO_LEVEL_HIGH,
	.gpio28 = GPIO_LEVEL_HIGH,
};

static const struct pch_gpio_set1 pch_gpio_set1_reset = {
};

static const struct pch_gpio_set1 pch_gpio_set1_invert = {
	.gpio3 = GPIO_INVERT,
	.gpio14 = GPIO_INVERT,
};

static const struct pch_gpio_set1 pch_gpio_set1_blink = {
};

static const struct pch_gpio_set2 pch_gpio_set2_mode = {
	.gpio32 = GPIO_MODE_GPIO,
	.gpio33 = GPIO_MODE_GPIO,
	.gpio34 = GPIO_MODE_GPIO,
	.gpio36 = GPIO_MODE_GPIO,
	.gpio37 = GPIO_MODE_GPIO,
	.gpio40 = GPIO_MODE_GPIO,
	.gpio41 = GPIO_MODE_GPIO,
	.gpio42 = GPIO_MODE_GPIO,
	.gpio43 = GPIO_MODE_GPIO,
	.gpio44 = GPIO_MODE_GPIO,
	.gpio45 = GPIO_MODE_GPIO,
	.gpio46 = GPIO_MODE_GPIO,
	.gpio47 = GPIO_MODE_GPIO,
	.gpio49 = GPIO_MODE_GPIO,
	.gpio50 = GPIO_MODE_GPIO,
	.gpio51 = GPIO_MODE_GPIO,
	.gpio52 = GPIO_MODE_GPIO,
	.gpio53 = GPIO_MODE_GPIO,
	.gpio54 = GPIO_MODE_GPIO,
	.gpio55 = GPIO_MODE_GPIO,
	.gpio59 = GPIO_MODE_GPIO,
};

static const struct pch_gpio_set2 pch_gpio_set2_direction = {
	.gpio32 = GPIO_DIR_INPUT,
	.gpio33 = GPIO_DIR_OUTPUT,
	.gpio34 = GPIO_DIR_INPUT,
	.gpio36 = GPIO_DIR_OUTPUT,
	.gpio37 = GPIO_DIR_OUTPUT,
	.gpio40 = GPIO_DIR_INPUT,
	.gpio41 = GPIO_DIR_INPUT,
	.gpio42 = GPIO_DIR_INPUT,
	.gpio43 = GPIO_DIR_INPUT,
	.gpio44 = GPIO_DIR_INPUT,
	.gpio45 = GPIO_DIR_INPUT,
	.gpio46 = GPIO_DIR_INPUT,
	.gpio47 = GPIO_DIR_OUTPUT,
	.gpio49 = GPIO_DIR_INPUT,
	.gpio50 = GPIO_DIR_INPUT,
	.gpio51 = GPIO_DIR_OUTPUT,
	.gpio52 = GPIO_DIR_INPUT,
	.gpio53 = GPIO_DIR_OUTPUT,
	.gpio54 = GPIO_DIR_OUTPUT,
	.gpio55 = GPIO_DIR_INPUT,
	.gpio59 = GPIO_DIR_INPUT,
};

static const struct pch_gpio_set2 pch_gpio_set2_level = {
	.gpio33 = GPIO_LEVEL_HIGH,
	.gpio36 = GPIO_LEVEL_HIGH,
	.gpio37 = GPIO_LEVEL_HIGH,
	.gpio47 = GPIO_LEVEL_LOW,
	.gpio51 = GPIO_LEVEL_HIGH,
	.gpio53 = GPIO_LEVEL_HIGH,
	.gpio54 = GPIO_LEVEL_HIGH,
};

static const struct pch_gpio_set2 pch_gpio_set2_reset = {
};

static const struct pch_gpio_set3 pch_gpio_set3_mode = {
	.gpio64 = GPIO_MODE_GPIO,
	.gpio65 = GPIO_MODE_GPIO,
	.gpio66 = GPIO_MODE_GPIO,
	.gpio68 = GPIO_MODE_GPIO,
	.gpio69 = GPIO_MODE_GPIO,
	.gpio70 = GPIO_MODE_GPIO,
	.gpio71 = GPIO_MODE_GPIO,
	.gpio72 = GPIO_MODE_GPIO,
	.gpio73 = GPIO_MODE_GPIO,
};

static const struct pch_gpio_set3 pch_gpio_set3_direction = {
	.gpio64 = GPIO_DIR_INPUT,
	.gpio65 = GPIO_DIR_INPUT,
	.gpio66 = GPIO_DIR_INPUT,
	.gpio68 = GPIO_DIR_INPUT,
	.gpio69 = GPIO_DIR_INPUT,
	.gpio70 = GPIO_DIR_INPUT,
	.gpio71 = GPIO_DIR_INPUT,
	.gpio72 = GPIO_DIR_OUTPUT,
	.gpio73 = GPIO_DIR_OUTPUT,
};

static const struct pch_gpio_set3 pch_gpio_set3_level = {
	.gpio72 = GPIO_LEVEL_HIGH,
	.gpio73 = GPIO_LEVEL_LOW,
};

static const struct pch_gpio_set3 pch_gpio_set3_reset = {
};

const struct pch_gpio_map mainboard_gpio_map = {
	.set1 = {
		.mode		= &pch_gpio_set1_mode,
		.direction	= &pch_gpio_set1_direction,
		.level		= &pch_gpio_set1_level,
		.blink		= &pch_gpio_set1_blink,
		.invert		= &pch_gpio_set1_invert,
		.reset		= &pch_gpio_set1_reset,
	},
	.set2 = {
		.mode		= &pch_gpio_set2_mode,
		.direction	= &pch_gpio_set2_direction,
		.level		= &pch_gpio_set2_level,
		.reset		= &pch_gpio_set2_reset,
	},
	.set3 = {
		.mode		= &pch_gpio_set3_mode,
		.direction	= &pch_gpio_set3_direction,
		.level		= &pch_gpio_set3_level,
		.reset		= &pch_gpio_set3_reset,
	},
};
