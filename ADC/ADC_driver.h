/*
 * ADC_driver.h
 *
 * Created: 9/22/2025
 * Author: Mohamed Galal
 *
 * Description: Header file for ADC driver.
 */

#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include <stdint.h>


void ADC_vinit(void);


void ADC_selectChannel(uint8_t ch);


uint16_t ADC_u16Read(void);

#endif /* ADC_DRIVER_H_ */
