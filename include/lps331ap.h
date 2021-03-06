/* COPYRIGHT (c) 2016-2018 Nova Labs SRL
 *
 * All rights reserved. All use of this software and documentation is
 * subject to the License Agreement located in the file LICENSE.
 */
 
/**
 * @file    lps331ap.h
 * @brief   LPS331AP MEMS interface module through SPI header.
 *
 * @addtogroup lps331ap
 * @{
 */

#ifndef _LPS331AP_H_
#define _LPS331AP_H_

#include "ch.h"
#include "hal.h"

/**
 * @name    LPS331AP register names
 * @{
 */
#define LSP331AP_WHO_AM_I			0x0F
#define LPS331AP_CTRL_REG1			0x20
#define LPS331AP_CTRL_REG2			0x21
#define LPS331AP_CTRL_REG3			0x22

#define BAR_DATA_READY                 789

/** @} */

typedef int32_t bar_data_t;

#ifdef __cplusplus
extern "C" {
#endif
  int init_lps331ap(SPIDriver *spip);
  uint8_t lps331apReadRegister(SPIDriver *spip, uint8_t reg);
  void lps331apWriteRegister(SPIDriver *spip, uint8_t reg, uint8_t value);
  void lps331ap_update(SPIDriver *spip);
  void lps331ap_drdy_callback(EXTDriver *extp, expchannel_t channel);
  thread_t *barRun(SPIDriver *spip, tprio_t prio);
#ifdef __cplusplus
}
#endif

#endif /* _LPS331AP_H_ */

/** @} */
