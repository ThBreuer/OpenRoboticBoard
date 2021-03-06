//*******************************************************************
/*!
\file   Module/ISC_USBdevice.cpp
\author Thomas Breuer
\date   11.12.2014, 17.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#include "lib.h"
#include "Module/ISC.h"

//*******************************************************************
//
// cISC_USBdevice
//
//*******************************************************************
//-------------------------------------------------------------------
cISC_USBdevice::cISC_USBdevice( cHwUSB    &usbIn,
                                BYTE       interfId,
                                cCRC::MODE crcMode )

: cISC( crcMode ),
  cUSBinterfClassVSC( usbIn, 1, interfId ),
  usb(usbIn),
  fifo(5)

{
}

//-------------------------------------------------------------------
void cISC_USBdevice::update( void )
{
}

//-------------------------------------------------------------------
void cISC_USBdevice::writeStream( BYTE  id,
                                  BYTE *data,
                                  BYTE  size,
                                  WORD  crc )
{
  cISC_USBdevice_DATA tmp;

  if( size > tmp.maxLength )
  {
    return;
  }
  memcpy( tmp.data, data, size );
  tmp.reserved = 0;
  tmp.id       = id;
  tmp.crcValue = crc;
  fifo << tmp;
}

//-------------------------------------------------------------------
int cISC_USBdevice::onTransmit( cISC_USBdevice_DATA &data )
{
  if( fifo >> data )
  {
  }
  else
  {
    memset( data.data, 0, data.maxLength );
    data.id       = 0xFF;
    data.reserved = 0;
    data.crcValue = 0;
  }
  return( true );
}

//-------------------------------------------------------------------
int cISC_USBdevice::onReceive( cISC_USBdevice_DATA &data)
{
  DataInterface *ptr = (DataInterface*)list.getFirst();

  while( ptr && ptr->id != data.id)
  {
    ptr = (DataInterface*)ptr->getNext();
  }

  if( ptr  && data.crcValue == crc((BYTE*)&data.id, ptr->dataLength+2) )
  {
    memcpy( ptr->dataRef, data.data, ptr->dataLength );
    ptr->update();
  }
  return( true );
}

//EOF
