//  This  is  an  independent  project  of  an  individual  developer.  Dear  PVS-Studio,  please  check  it.
//  PVS-Studio  Static  Code  Analyzer  for  C,  C++  and  C#:  http://www.viva64.com

#include  "result.hpp"

const  char*  ResultException::what()  const  noexcept  {  return  message_;  }