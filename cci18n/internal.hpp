/*
 * CC_I18N_INTERNAL_
 *
 *  Created on: 16.1.2015
 *      Author: akin
 */

#ifndef CC_I18N_INTERNAL_HPP_
#define CC_I18N_INTERNAL_HPP_

#include <string>
#include <unordered_map>
#include <memory>	// c++11 std::shared_ptr

namespace core {
namespace cci18n {
	
	using Language = std::unordered_map<std::string , std::string>;
	using SharedLanguage = std::shared_ptr<Language>;
	
} // cci18nns
} // corens

#endif // CC_I18N_INTERNAL_HPP_
