#ifndef __IP2906_REGISTER__
#define __IP2906_REGISTER__

#include <linux/mutex.h>
#include <linux/types.h>
#include <linux/gpio.h>
#include <linux/i2c.h>

#define IP2906_DEBUG
#ifdef IP2906_DEBUG
#define IP2906_INFO(format, args...) printk(KERN_ERR "[IP2906]"format, ##args)
#else
#define IP2906_INFO(format, args...) printk(KERN_INFO "[IP2906]"format, ##args)
#endif
#define IP2906_ERR(format, args...) printk(KERN_ERR "[IP2906]"format, ##args)

/* Registers */
#define IP2906_IIC_ADDR		0x00
#define IP2906_MFP_PAD		0x01
#define IP2906_GPIO_CTRL	0x02
#define IP2906_INT_CTRL		0x03
#define IP2906_CMU_CLKEN	0x04
#define IP2906_DEV_RST		0x05
#define IP2906_CMU_ANALOG	0x06
#define IP2906_PMU_ANALOG0	0x07
#define IP2906_PMU_ANALOG1	0x08
#define IP2906_IREF_CTL		0x09
#define IP2906_EFUSE_CTL	0x0a
#define IP2906_PAD_DRV		0x0b
#define IP2906_DEBUG_IE		0x0c
#define IP2906_DEBUG_OE		0x0d
#define IP2906_DEBUG_SEL	0x0e
#define IP2906_BIST_CTRL	0x0f
#define IP2906_TEST_CTRL	0x1f

/* Audio Registers */
#define IP2906_AUDIO_BASE_ADDR	0x20
#define IP2906_IIS_CONFIG		(0x00+IP2906_AUDIO_BASE_ADDR)
#define IP2906_IIS_TXMIX		(0x01+IP2906_AUDIO_BASE_ADDR)
#define IP2906_ADC_CTL			(0x02+IP2906_AUDIO_BASE_ADDR)
#define IP2906_ADC_VOL			(0x03+IP2906_AUDIO_BASE_ADDR)
#define IP2906_DAC_CTL			(0x04+IP2906_AUDIO_BASE_ADDR)
#define IP2906_DAC_VOL			(0x05+IP2906_AUDIO_BASE_ADDR)
#define IP2906_DAC_MIX			(0x06+IP2906_AUDIO_BASE_ADDR)
#define IP2906_AUDIO_DEBUG		(0x07+IP2906_AUDIO_BASE_ADDR)
#define IP2906_AUI_CTL1			(0x10+IP2906_AUDIO_BASE_ADDR)
#define IP2906_AUI_CTL2			(0x11+IP2906_AUDIO_BASE_ADDR)
#define IP2906_AUI_CTL3			(0x12+IP2906_AUDIO_BASE_ADDR)
#define IP2906_AUI_CTL4			(0x13+IP2906_AUDIO_BASE_ADDR)
#define IP2906_AUI_CTL5			(0x14+IP2906_AUDIO_BASE_ADDR)
#define IP2906_AUO_CTL1			(0x15+IP2906_AUDIO_BASE_ADDR)
#define IP2906_AUO_CTL2			(0x16+IP2906_AUDIO_BASE_ADDR)
#define IP2906_AUO_CTL3			(0x17+IP2906_AUDIO_BASE_ADDR)
#define IP2906_AUO_CTL4			(0x18+IP2906_AUDIO_BASE_ADDR)
#define IP2906_AUO_CTL5			(0x19+IP2906_AUDIO_BASE_ADDR)

/* Ethernet PHY Registers */
#define IP2906_PHY_BASE_ADDR	0x40
#define IP2906_PHY_SMI_STAT		(0x00+IP2906_PHY_BASE_ADDR)
#define IP2906_PHY_SMI_CONFIG	(0x01+IP2906_PHY_BASE_ADDR)
#define IP2906_PHY_SMI_DATA		(0x02+IP2906_PHY_BASE_ADDR)
#define IP2906_PHY_CTRL			(0x03+IP2906_PHY_BASE_ADDR)
#define IP2906_PHY_ID1			(0x04+IP2906_PHY_BASE_ADDR)
#define IP2906_PHY_ID2			(0x05+IP2906_PHY_BASE_ADDR)
#define IP2906_PHY_ADDR			(0x06+IP2906_PHY_BASE_ADDR)
#define IP2906_PHY_LED			(0x07+IP2906_PHY_BASE_ADDR)
#define IP2906_PHY_INT_CTRL		(0x08+IP2906_PHY_BASE_ADDR)
#define IP2906_PHY_INT_STAT		(0x09+IP2906_PHY_BASE_ADDR)
#define IP2906_PHY_HW_RST		(0x0a+IP2906_PHY_BASE_ADDR)
#define IP2906_PHY_CONFIG		(0x0b+IP2906_PHY_BASE_ADDR)
#define IP2906_PHY_PLL_CTL0		(0x0c+IP2906_PHY_BASE_ADDR)
#define IP2906_PHY_PLL_CTL1		(0x0d+IP2906_PHY_BASE_ADDR)
#define IP2906_PHY_DBG0			(0x0e+IP2906_PHY_BASE_ADDR)
#define IP2906_PHY_DBG1			(0x0f+IP2906_PHY_BASE_ADDR)
#define IP2906_PHY_DBG2			(0x10+IP2906_PHY_BASE_ADDR)
#define IP2906_PHY_DBG3			(0x11+IP2906_PHY_BASE_ADDR)
#define IP2906_PHY_DBG4			(0x12+IP2906_PHY_BASE_ADDR)

/* CVBS Registers */
#define IP2906_CVBS_BASE_ADDR	0x60
#define IP2906_CVBS_CTRL		(0x00+IP2906_CVBS_BASE_ADDR)
#define IP2906_CVBS_COLOR_CTRL	(0x01+IP2906_CVBS_BASE_ADDR)
#define IP2906_CVBS_BRIGHT_CTRL	(0x02+IP2906_CVBS_BASE_ADDR)
#define IP2906_CVBS_HUE_CTRL	(0x03+IP2906_CVBS_BASE_ADDR)
#define IP2906_CVBS_SBCP_CTRL	(0x04+IP2906_CVBS_BASE_ADDR)
#define IP2906_CVBS_SBCF_CTRL	(0x05+IP2906_CVBS_BASE_ADDR)
#define IP2906_CVBS_APTD_CTRL	(0x06+IP2906_CVBS_BASE_ADDR)
#define IP2906_CVBS_SIN_CTRL	(0x07+IP2906_CVBS_BASE_ADDR)
#define IP2906_CVBS_HDAC_TEST	(0x08+IP2906_CVBS_BASE_ADDR)
#define IP2906_CVBS_ROM_TEST	(0x09+IP2906_CVBS_BASE_ADDR)
#define IP2906_CVBS_ANALOG_REG	(0x0a+IP2906_CVBS_BASE_ADDR)
#define IP2906_CVBS_CLK_CTRL	(0x0b+IP2906_CVBS_BASE_ADDR)

int ip2906_write(uint8_t reg, uint16_t val);
int ip2906_read(uint8_t reg, uint16_t *val);

#endif
