//*****************************************************************
/*
  JackTrip: A System for High-Quality Audio Network Performance
  over the Internet

  Copyright (c) 2008 Juan-Pablo Caceres, Chris Chafe.
  SoundWIRE group at CCRMA, Stanford University.
  
  Permission is hereby granted, free of charge, to any person
  obtaining a copy of this software and associated documentation
  files (the "Software"), to deal in the Software without
  restriction, including without limitation the rights to use,
  copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the
  Software is furnished to do so, subject to the following
  conditions:
  
  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
  OTHER DEALINGS IN THE SOFTWARE.
*/
//*****************************************************************

/**
 * \file DataProtocol.cpp
 * \author Juan-Pablo Caceres
 * \date June 2008
 */

#include "DataProtocol.h"
#include "globals.h"
#include "JackAudioInterface.h"
#include "PacketHeader.h"

#include <iostream>
#include <cstdlib>

#include <QHostInfo>
#include <QHostAddress>

using std::cout; using std::endl;


//*******************************************************************************
DataProtocol::DataProtocol(const runModeT runmode,
			   const packetHeaderTypeT headertype) : 
  mStopped(false), mHasPacketsToReceive(false), mRunMode(runmode), mHeader(NULL)
{
  switch (headertype) {
  case DEFAULT :
    mHeader = new DefaultHeader;
    break;
  case JAMLINK :
    //mHeader = new JamLinkHeader;
    break;
  default:
    std::cerr << "ERROR: Undefined Header Type" << endl;
    std::cerr << "Exiting Program..." << endl;
    std::exit(1);
    break;
  }
}


//*******************************************************************************
DataProtocol::~DataProtocol()
{
  delete mHeader;
}


//*******************************************************************************
void DataProtocol::fillHeaderCommonFromJack(const JackAudioInterface& jackaudio)
{
  mHeader->fillHeaderCommonFromJack(jackaudio);
}