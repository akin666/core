//
//  helpers.hpp
//  Tracker
//
//  Created by mikael korpela on 03/11/14.
//  Copyright (c) 2014 mikael korpela. All rights reserved.
//

#ifndef CORE_helpers_hpp
#define CORE_helpers_hpp

#define DPI2DPMM 0.0394f
#define DPMM2DPI 25.4f

#define M2MM 1000.0f
#define MM2M 0.001f;

namespace core {

float dpi2dpmm( float dpi );
float dpmm2dpi( float dpmm );

} // corens
    
#endif
