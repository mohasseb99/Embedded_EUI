#include "DIO.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"

/*
 * Description:  Returns the value of the specified DIO channel. *
 * Parameters: ChannelId : ID of DIO channel
 * Returns: Dio_Level-Type STD_HIGH The physical level of the corresponding Pin is STD_HIGH
 *                         STD_LOW The physical level of the corresponding Pin is STD_LOW
 */
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
{
    Dio_PortType portNum = ChannelId / NUMBER_OF_PINS;  /* to know port of this channel id */
    Dio_ChannelType pinNum = ChannelId % NUMBER_OF_PINS; /* to know number of this pin */

    Dio_LevelType value = 1U;  /* init value */

    switch(portNum){
    case PORTA:
        value = getBit(GPIO_PORTA_DATA_R, pinNum);
        break;
    case PORTB:
        value = getBit(GPIO_PORTB_DATA_R, pinNum);
        break;
    case PORTC:
        value = getBit(GPIO_PORTC_DATA_R, pinNum);
        break;
    case PORTD:
        value = getBit(GPIO_PORTD_DATA_R, pinNum);
        break;
    case PORTE:
        value = getBit(GPIO_PORTE_DATA_R, pinNum);
        break;
    case PORTF:
        value = getBit(GPIO_PORTF_DATA_R, pinNum);
        break;
    default:
        break;
    }

    return value;
}

/*
 * Description: Service to set a level of a channel.
 *
 * Parameters(In): ChannelId : ID of DIO channel
 *                 Level : Value to be written
 * Returns: None
 */
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    Dio_PortType portNum = ChannelId / NUMBER_OF_PINS;  /* to know port of this channel id */
    Dio_ChannelType pinNum = ChannelId % NUMBER_OF_PINS; /* to know number of this pin */

    switch (portNum){
    case PORTA:
        GPIO_PORTA_BIT_DATA(pinNum) = (Level<<pinNum);
        break;
    case PORTB:
        GPIO_PORTB_BIT_DATA(pinNum) = (Level<<pinNum);
        break;
    case PORTC:
        GPIO_PORTC_BIT_DATA(pinNum) = (Level<<pinNum);
        break;
    case PORTD:
        GPIO_PORTD_BIT_DATA(pinNum) = (Level<<pinNum);
        break;
    case PORTE:
        GPIO_PORTE_BIT_DATA(pinNum) = (Level<<pinNum);
        break;
    case PORTF:
        GPIO_PORTF_BIT_DATA(pinNum) = (Level<<pinNum);
        break;
    default:
        break;
    }
}

/*
 * Description: Returns the level of all channels of that port.
 * Parameters(In): PortId : ID of DIO Port
 * Returns: Dio_PortLevelType : Level of all channels of that port
 */
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId)
{
    Dio_PortLevelType result;

    switch(PortId){
    case PORTA:
        result = (uint8_t)GPIO_PORTA_DATA_R;
        break;
    case PORTB:
        result = (uint8_t)GPIO_PORTB_DATA_R;
        break;
    case PORTC:
        result = (uint8_t)GPIO_PORTC_DATA_R;
        break;
    case PORTD:
        result = (uint8_t)GPIO_PORTD_DATA_R;
        break;
    case PORTE:
        result = (uint8_t)GPIO_PORTE_DATA_R;
        break;
    case PORTF:
        result = (uint8_t)GPIO_PORTF_DATA_R;
        break;
    default:
        break;
    }
    return result;
}

/*
 * Description: Service to set a value of the port.
 * Parameters(In): PortId : ID of DIO Port
 *                 Level : Value to be written
 * Returns: None
 */
void Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level)
{
    switch(PortId){
    case PORTA:
        GPIO_PORTA_DATA_R = Level;
        break;
    case PORTB:
        GPIO_PORTB_DATA_R = Level;
        break;
    case PORTC:
        GPIO_PORTC_DATA_R = Level;
        break;
    case PORTD:
        GPIO_PORTD_DATA_R = Level;
        break;
    case PORTE:
        GPIO_PORTE_DATA_R = Level;
        break;
    case PORTF:
        GPIO_PORTF_DATA_R = Level;
        break;
    default:
        break;
    }
}
