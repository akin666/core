/*
 * TCOLOR
 *
 *  Created on: 1.7.2012
 *      Author: akin
 */

#ifndef TCOLOR_H_123_
#define TCOLOR_H_123_

namespace core {
namespace graphics {

template<class T>
class TColor3
{
public:
	union { T r, h, y; };
	union { T g, s, u; };
	union { T b, i, l, p, v; };
public:
	TColor3()
	{}
	
	TColor3(const TColor3<T>& other)
	: r(other.r)
	, g(other.g)
	, b(other.b)
	{}
	
	TColor3(T r, T g, T b)
	: r(r)
	, g(g)
	, b(b)
	{}
	
	TColor3<T>& operator = (const TColor3<T>& other)
	{
		r = other.r;
		g = other.g;
		b = other.b;
		
		return *this;
	}
	
	TColor3<T>& operator += (const TColor3<T>& o)
	{
		r += o.r;
		g += o.g;
		b += o.b;
		return *this;
	}
	
	TColor3<T>& operator -= (const TColor3<T>& o)
	{
		r -= o.r;
		g -= o.g;
		b -= o.b;
		return *this;
	}
	
	TColor3<T>& operator *= (const TColor3<T>& o)
	{
		r *= o.r;
		g *= o.g;
		b *= o.b;
		return *this;
	}
	
	TColor3<T>& operator /= (const TColor3<T>& o)
	{
		r /= o.r;
		g /= o.g;
		b /= o.b;
		return *this;
	}
	
	TColor3<T>& operator += (T num)
	{
		r += num;
		g += num;
		b += num;
		return *this;
	}
	
	TColor3<T>& operator -= (T num)
	{
		r -= num;
		g -= num;
		b -= num;
		return *this;
	}
	
	TColor3<T>& operator *= (T num)
	{
		r *= num;
		g *= num;
		b *= num;
		return *this;
	}
	
	TColor3<T>& operator /= (T num)
	{
		r /= num;
		g /= num;
		b /= num;
		return *this;
	}
};

template <typename T>
TColor3<T> operator+ ( const TColor3<T>& a, const T& b )
{
	return TColor3<T>(
					  a.r + b ,
					  a.g + b ,
					  a.b + b
					  );
}

template <typename T>
TColor3<T> operator- ( const TColor3<T>& a, const T& b )
{
	return TColor3<T>(
					  a.r - b ,
					  a.g - b ,
					  a.b - b
					  );
}

template <typename T>
TColor3<T> operator* ( const TColor3<T>& a, const T& b )
{
	return TColor3<T>(
					  a.r * b ,
					  a.g * b ,
					  a.b * b
					  );
}

template <typename T>
TColor3<T> operator/ ( const TColor3<T> & a, const T& b )
{
	return TColor3<T>(
					  a.r / b ,
					  a.g / b ,
					  a.b / b
					  );
}

template <typename T>
TColor3<T> operator+ ( const TColor3<T>& a, const TColor3<T>& b )
{
	return TColor3<T>(
					  a.r + b.r ,
					  a.g + b.g ,
					  a.b + b.b
					  );
}

template <typename T>
TColor3<T> operator- ( const TColor3<T>& a, const TColor3<T>& b )
{
	return TColor3<T>(
					  a.r - b.r ,
					  a.g - b.g ,
					  a.b - b.b
					  );
}

template <typename T>
TColor3<T> operator* ( const TColor3<T>& a, const TColor3<T>& b )
{
	return TColor3<T>(
					  a.r * b.r ,
					  a.g * b.g ,
					  a.b * b.b
					  );
}

template <typename T>
TColor3<T> operator/ ( const TColor3<T> & a, const TColor3<T>& b )
{
	return TColor3<T>(
					  a.r / b.r ,
					  a.g / b.g ,
					  a.b / b.b
					  );
}

template<class T>
class TColor4
{
public:
	union { T r, h; };
	union { T g, s; };
	union { T b, i, l, p; };
	union { T a; };
public:
	TColor4()
	{}
	
	TColor4(const TColor4<T>& other)
	: r(other.r)
	, g(other.g)
	, b(other.b)
	, a(other.a)
	{}
	
	TColor4(T r, T g, T b, T a)
	: r(r)
	, g(g)
	, b(b)
	, a(a)
	{}
	
	TColor4<T>& operator = (const TColor4<T>& other)
	{
		r = other.r;
		g = other.g;
		b = other.b;
		a = other.a;
		
		return *this;
	}
};
    
} // graphicsns
} // corens

#endif // TCOLOR_H_123_
