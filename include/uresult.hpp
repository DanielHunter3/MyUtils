#pragma  once

#include  "result.hpp"

enum  class  EnumError  {
  //...
};

template  <typename  T>
using  UResult  =  Result<T,  EnumError>;

//  template  <typename  T>
//  using  UResult  =  Result<T,  StructError>;