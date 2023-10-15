/*
 * DIO.h
 *
 *  Created on: Aug 13, 2023
 *      Author: mohas
 */

#ifndef DIO_H_
#define DIO_H_

#include <stdint.h>

#define STD_HIGH 1U
#define STD_LOW 0U

#define NUMBER_OF_PINS 8U

#define PORTA   0U
#define PORTB   1U
#define PORTC   2U
#define PORTD   3U
#define PORTE   4U
#define PORTF   5U


#define PF1_ID 41U
#define PF2_ID 42U
#define PF3_ID 43U

typedef uint8_t Dio_ChannelType;
typedef uint8_t Dio_PortType;
typedef uint8_t Dio_LevelType;
typedef uint8_t Dio_PortLevelType;


/*
 * Description:  Returns the value of the specified DIO channel. *
 * Parameters: ChannelId : ID of DIO channel
 * Returns: Dio_Level-Type STD_HIGH The physical level of the corresponding Pin is STD_HIGH
 *                         STD_LOW The physical level of the corresponding Pin is STD_LOW
 */
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId);

/*
 * Description: Service to set a level of a channel.
 *
 * Parameters(In): ChannelId : ID of DIO channel
 *                 Level : Value to be written
 * Returns: None
 */
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level);

/*
 * Description: Returns the level of all channels of that port.
 * Parameters(In): PortId : ID of DIO Port
 * Returns: Dio_PortLevelType : Level of all channels of that port
 */
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId);

/*
 * Description: Service to set a value of the port.
 * Parameters(In): PortId : ID of DIO Port
 *                 Level : Value to be written
 * Returns: None
 */
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level);


#endif /* DIO_H_ */
