//*******************************************************************
/*!
\file   Memory_RAM.h
\author Thomas Breuer (Bonn-Rhein-Sieg University of Applied Sciences)
\date   23.03.2016

This file is released under the MIT License.
*/

//*******************************************************************
#ifndef _HW_MEMORY_RAM_H
#define _HW_MEMORY_RAM_H

//*******************************************************************
#include "Com/Hardware/Memory/Memory.h"

//*******************************************************************
/*!
\class cHwMemory_RAM

\brief Implementation of the battery buffered RAM

\example cHwMemory.cpp
*/
class cHwMemory_RAM : public cHwMemory
{
  public:
    //---------------------------------------------------------------
    /*! Initialize battery buffered RAM hardware
    */
    cHwMemory_RAM( void );

    //---------------------------------------------------------------
    virtual void lock( ) {}
    virtual void unlock() {}

  private:
    //---------------------------------------------------------------
    virtual void writeByte( DWORD addr,
                            BYTE  data );

    //---------------------------------------------------------------
    virtual BYTE readByte( DWORD addr );

  public:
    virtual BYTE *getAddr() { return( ptr ); }


  private:
    //---------------------------------------------------------------
    BYTE *ptr;

}; //cHwMemory_RAM

#endif
