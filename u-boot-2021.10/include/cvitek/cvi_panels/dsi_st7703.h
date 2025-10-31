#ifndef _MIPI_TX_PARAM_ST_7703_H_
#define _MIPI_TX_PARAM_ST_7703_H_

#ifndef __UBOOT__
#include <linux/vo_mipi_tx.h>
#include <linux/cvi_comm_mipi_tx.h>
#else
#include <cvi_mipi.h>
#endif

/*
#define ST7703_VACT	854
#define ST7703_VSA		2
#define ST7703_VBP		20
#define ST7703_VFP		20

#define ST7703_HACT	480
#define ST7703_HSA		10
#define ST7703_HBP		40
#define ST7703_HFP		40
*/

#define ST7703_VACT	1280
#define ST7703_VSA		4
#define ST7703_VBP		16
#define ST7703_VFP		16

#define ST7703_HACT	720
#define ST7703_HSA		20
#define ST7703_HBP		40
#define ST7703_HFP		40

#define DXQ_PIXEL_CLK(x) ((x##_VACT + x##_VSA + x##_VBP + x##_VFP) \
	* (x##_HACT + x##_HSA + x##_HBP + x##_HFP) * 60 / 1000)

struct combo_dev_cfg_s dev_cfg_st7703 = {
	.devno = 0,
	.lane_id = {MIPI_TX_LANE_0, MIPI_TX_LANE_CLK, MIPI_TX_LANE_1, -1, -1},
	.lane_pn_swap = {false, false, false, false, false},
	.output_mode = OUTPUT_MODE_DSI_VIDEO,
	.video_mode = BURST_MODE,
	.output_format = OUT_FORMAT_RGB_24_BIT,
	.sync_info = {
		.vid_hsa_pixels = ST7703_HSA,
		.vid_hbp_pixels = ST7703_HBP,
		.vid_hfp_pixels = ST7703_HFP,
		.vid_hline_pixels = ST7703_HACT,
		.vid_vsa_lines = ST7703_VSA,
		.vid_vbp_lines = ST7703_VBP,
		.vid_vfp_lines = ST7703_VFP,
		.vid_active_lines = ST7703_VACT,
		.vid_vsa_pos_polarity = true,
		.vid_hsa_pos_polarity = false,
	},
	.pixel_clk = DXQ_PIXEL_CLK(ST7703),
};

const struct hs_settle_s hs_timing_cfg_st7703 = { .prepare = 6, .zero = 32, .trail = 1 };

#ifndef CVI_U8
#define CVI_U8 unsigned char
#endif

// Data arrays for DSI commands
static CVI_U8 data_ST770_0[] = {0xB9,0xF1,0x12,0x83}; // Set EXTC
static CVI_U8 data_ST770_1[] = {0xB1,0x00,0x00,0x00,0xDA,0x80};
static CVI_U8 data_ST770_2[] = {0xB2,0xC8,0x02,0x70}; // Set RSO
static CVI_U8 data_ST770_3[] = {0xB3,0x10,0x10,0x28,0x28,0x03,0xFF,0x00,0x00,0x00,0x00}; // SET RGB
static CVI_U8 data_ST770_4[] = {0xB4,0x80}; // Set Panel Inversion
static CVI_U8 data_ST770_5[] = {0xB5,0x0A,0x0A}; // Set BGP
static CVI_U8 data_ST770_6[] = {0xB6,0x48,0x48}; // Set VCOM
static CVI_U8 data_ST770_7[] = {0xB8,0x26,0x22,0xF0,0x13}; // Set ECP
static CVI_U8 data_ST770_8[] = {0xBA,0x31,0x81,0x05,0xF9,0x0E,0x0E,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x25,0x00,0x90,0x0A,0x00,0x00,0x01,0x4F,0x01,0x00,0x00,0x37}; // Set DSI
static CVI_U8 data_ST770_9[] = {0xBC,0x47}; // Set VDC
static CVI_U8 data_ST770_10[] = {0xBF,0x02,0x11,0x00}; // Set PCR
static CVI_U8 data_ST770_11[] = {0xC0,0x73,0x73,0x50,0x50,0x00,0x00,0x12,0x70,0x00}; // Set SCR
static CVI_U8 data_ST770_12[] = {0xC1,0x52,0xC0,0x32,0x32,0x99,0xC4,0xFF,0xFF,0xCC,0xCC,0x77,0x77}; // Set POWER
static CVI_U8 data_ST770_13[] = {0xC6,0x82,0x00,0xBF,0xFF,0x00,0xFF}; // SCR
static CVI_U8 data_ST770_14[] = {0xC7,0xB8,0x00,0x0A,0x00,0x00,0x00};
static CVI_U8 data_ST770_15[] = {0xC8,0x10,0x40,0x1E,0x02};
static CVI_U8 data_ST770_16[] = {0xCC,0x0B}; // Set Panel
static CVI_U8 data_ST770_17[] = {0xE0,0x00,0x09,0x12,0x29,0x3A,0x3F,0x45,0x3A,0x06,0x0C,0x0F,0x13,0x15,0x14,0x14,0x0F,0x16,0x00,0x09,0x12,0x29,0x3A,0x3F,0x45,0x3A,0x06,0x0C,0x0F,0x13,0x15,0x14,0x14,0x0F,0x16}; // Set Gamma2.2
static CVI_U8 data_ST770_18[] = {0xE3,0x07,0x07,0x0B,0x0B,0x0B,0x0B,0x00,0x00,0x00,0x00,0xFF,0x80,0xC0,0x10}; // Set EQ
static CVI_U8 data_ST770_19[] = {0xE9,0xC8,0x10,0x0A,0x05,0x05,0x80,0x38,0x12,0x31,0x23,0x4F,0x86,0x64,0x38,0x47,0x08,0x38,0x00,0x01,0x04,0x00,0x00,0x38,0x00,0x01,0x04,0x00,0x00,0xA8,0x46,0x02,0x88,0x88,0x88,0x88,0x88,0x88,0x9F,0x02,0xA8,0x57,0x13,0x88,0x88,0x88,0x88,0x88,0x88,0x9F,0x13,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}; // Set GIP
static CVI_U8 data_ST770_20[] = {0xEA,0x00,0x1A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xAF,0x31,0x75,0x88,0x88,0x88,0x88,0x88,0x88,0x98,0x31,0xAF,0x20,0x64,0x88,0x88,0x88,0x88,0x88,0x88,0x98,0x20,0x23,0x20,0x00,0x01,0x4C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x0A,0x00,0x00,0x40,0x80,0x38,0x40,0x80,0x81,0x00}; // Set GIP2
static CVI_U8 data_ST770_21[] = {0xEF,0xFF,0xFF,0x01};
static CVI_U8 data_ST770_22[] = {0x11}; // Sleep Out
static CVI_U8 data_ST770_23[] = {0x29}; // Display On

// DSI command type definitions
#define TYPE1_DCS_SHORT_WRITE 0x05
#define TYPE2_DCS_SHORT_WRITE 0x15
#define TYPE3_DCS_LONG_WRITE 0x39
#define TYPE3_GENERIC_LONG_WRITE 0x29

// DSI initialization command sequence
const struct dsc_instr dsi_init_cmds_st7703[] = {
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 4, .data = data_ST770_0 },
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 6, .data = data_ST770_1 },
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 4, .data = data_ST770_2 },
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 11, .data = data_ST770_3 },
    {.delay = 0, .data_type = TYPE2_DCS_SHORT_WRITE, .size = 2, .data = data_ST770_4 },
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 3, .data = data_ST770_5 },
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 3, .data = data_ST770_6 },
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 5, .data = data_ST770_7 },
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 28, .data = data_ST770_8 },
    {.delay = 0, .data_type = TYPE2_DCS_SHORT_WRITE, .size = 2, .data = data_ST770_9 },
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 4, .data = data_ST770_10 },
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 10, .data = data_ST770_11 },
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 13, .data = data_ST770_12 },
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 7, .data = data_ST770_13 },
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 7, .data = data_ST770_14 },
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 5, .data = data_ST770_15 },
    {.delay = 0, .data_type = TYPE2_DCS_SHORT_WRITE, .size = 2, .data = data_ST770_16 },
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 35, .data = data_ST770_17 },
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 15, .data = data_ST770_18 },
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 64, .data = data_ST770_19 },
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 62, .data = data_ST770_20 },
    {.delay = 0, .data_type = TYPE3_DCS_LONG_WRITE, .size = 4, .data = data_ST770_21 },
    {.delay = 250, .data_type = TYPE1_DCS_SHORT_WRITE, .size = 1, .data = data_ST770_22 }, // Sleep Out with 250ms delay
    {.delay = 50, .data_type = TYPE1_DCS_SHORT_WRITE, .size = 1, .data = data_ST770_23 }, // Display On with 50ms delay
};

#else
#error "MIPI_TX_PARAM multi-delcaration!!"
#endif
