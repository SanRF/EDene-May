//
//  busca.h
//  EjerExtra
//
//  Created by Santiago Rodriguez Fernandez on 15/05/15.
//  Copyright (c) 2015 Santiago Rodriguez Fernandez. All rights reserved.
//

#ifndef EjerExtra_busca_h
#define EjerExtra_busca_h

#include <iostream>
class FindAttribute
{
    altura name_;
    
public:
    FindAttribute(const int& name)
    : name_(name)
    {}
    
    bool operator()(const Attribute& attr)
    { return attr.attributeName == name_; }
};

// ...

std::vector<Attribute> attributes;
std::vector<Attribute>::iterator attr_iter =
std::find_if(attributes.begin(), attributes.end(),
             FindAttribute("Altura"));
if (attr_iter != attributes.end())
{
    
}
#endif
