/*
 * ccctypes
 *
 *  Created on: 1.7.2012
 *      Author: akin
 *
 *      defines standard types.
 */

#ifndef CCCTYPES_H_123_
#define CCCTYPES_H_123_

#include "os.hpp"
#include <limits>	// c++ limits
#include <climits>	// int limits
#include <cfloat>	// float limits
#include <cstdint>	// int8_t, int16_t, int32_t,int64_t , uint8_t, uint16_t, uint32_t, uint64_t etc.
#include <atomic>	// atomic things.
#include <string>
#include <memory>	// c++11 std::shared_ptr
#include <list>
#include <vector>
#include <unordered_map>
#include <map>
#include <tuple> 	// std::make_tuple + tuples in general.
#include "exceptions/exception.hpp" // core exception type

namespace core {

#define ducktype /*just programming hint*/
#define ducked //

// Common defines:
#ifndef DELTA
# define DELTA 0.0001f
#endif
#ifndef PI
# define PI 3.141593f
#endif
#ifndef PI2
# define PI2 6.283185f
#endif
#ifndef DEG2RAD
# define DEG2RAD 0.017453292519943
#endif
 // PI/360.0f =
#ifndef PI_OVER_360
# define PI_OVER_360 0.0087266462599716478846184538424431
#endif

// Access defines
#ifndef ACCESS_NONE
# define ACCESS_NONE 0x0000
#endif
#ifndef ACCESS_READ
# define ACCESS_READ 0x0001
#endif
#ifndef ACCESS_WRITE
# define ACCESS_WRITE 0x0002
#endif
#ifndef ACCESS_CREATE
# define ACCESS_CREATE 0x0004
#endif
#ifndef ACCESS_APPEND
# define ACCESS_APPEND 0x0008
#endif
#ifndef ACCESS_OVERWRITE
# define ACCESS_OVERWRITE 0x0010
#endif

#define ACTION_INACTIVE 0
#define ACTION_ACTIVE 	1

// Standard types
#ifndef SKIP_STANDARD_TYPES
	// signed types
	using int8 = int8_t;
	using int16 = int16_t;
	using int32 = int32_t;
	using int64 = int64_t;

	// unsigned types
	using uint8 = uint8_t;
	using uint16 = uint16_t;
	using uint32 = uint32_t;
	using uint64 = uint64_t;

	// floating point
	using float32 = float;
	using float64 = double;
//	using float128 = quad;
#endif

#ifndef SKIP_HELPER_TYPES
	using schar = int8;
	using uchar = uint8;
	using sshort = int16;
	using ushort = uint16;
	using sint = int32;
	using uint = uint32;
	using slong = int64;
# ifndef OS_LINUX
	using ulong = uint64;
# endif
	using vec = float32;
#endif
    
// Byte
using Byte = uint8;

// Codepoints
using UNICODE = uint32;
using UTF32 = uint32;
using UNICODE16 = uint16;
using UTF16 = uint16;
using UTF8 = uint8;

// Common
using BufferIndex = uint32;
using EntityID = uint64;

using ByteArray = std::vector<uchar>;
using SharedByteArray = std::shared_ptr<ByteArray>;
using ConstSharedByteArray = std::shared_ptr<const ByteArray>;
using WeakByteArray = std::weak_ptr<ByteArray>;
using ConstWeakByteArray = std::weak_ptr<const ByteArray>;

// std::string types
using StringPos = std::string::size_type;
using StringSet = std::vector<std::string>;

// Primitive types
namespace Primitive
{
	enum Type
	{
		NONE = 				0x00000,
		POINT = 			0x00001,
		LINE = 				0x00002,
		LINE_STRIP =		0x00004,
		TRIANGLE = 			0x00008,
		TRIANGLE_STRIP = 	0x00010,
		TRIANGLE_FAN = 		0x00020,
		QUAD = 				0x00040,
		QUAD_STRIP = 		0x00080,
		POLYGON = 			0x00100
	};
};

} // corens
    
#endif // STDTYPES_H_123_
