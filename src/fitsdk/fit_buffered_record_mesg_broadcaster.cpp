////////////////////////////////////////////////////////////////////////////////
// The following FIT Protocol software provided may be used with FIT protocol
// devices only and remains the copyrighted property of Dynastream Innovations Inc.
// The software is being provided on an "as-is" basis and as an accommodation,
// and therefore all warranties, representations, or guarantees of any kind
// (whether express, implied or statutory) including, without limitation,
// warranties of merchantability, non-infringement, or fitness for a particular
// purpose, are specifically disclaimed.
//
// Copyright 2014 Dynastream Innovations Inc.
////////////////////////////////////////////////////////////////////////////////
// ****WARNING****  This file is auto-generated!  Do NOT edit this file.
// Profile Version = 12.10Release
// Tag = $Name$
////////////////////////////////////////////////////////////////////////////////


#include "fit_buffered_record_mesg_broadcaster.hpp"

namespace fit
{

BufferedRecordMesgBroadcaster::BufferedRecordMesgBroadcaster(void)
{
}

void BufferedRecordMesgBroadcaster::AddListener(BufferedRecordMesgListener& mesgListener)
{
   listeners.push_back(&mesgListener);
}

void BufferedRecordMesgBroadcaster::OnMesg(RecordMesg& mesg)
{
   bufferedRecordMesg.SetFields(mesg);
   
   for (int i = 0; i < (int)listeners.size(); i++)
   {
      listeners[i]->OnMesg(bufferedRecordMesg);
   }
}

} // namespace fit