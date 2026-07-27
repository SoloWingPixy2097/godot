/** --------------------------------------------------------------------------------
*** Name     : nlohmann_json.hpp
*** Purpose  : Wrapper for Nlohmann's Json For Modern C++ Library - Implementation
*** Copyright: Royal NLR, NARSIM.org, 2025
*** Created by: Alex Schmitt, 26/03/2025
*** -------------------------------------------------------------------------------*/

#pragma once

#include "json.hpp"

//Convenience accessor
using Json = nlohmann::json;

namespace jsonutils
{
    /**
     * @brief Retrieves a value of @tparam Type_T for the given @param key if present within the @param data
     * If the key does not exist, writes @param defaultTo to @param outValue
     * @param leaveIntact Whether or not to write to @param outValue
     * @return Whether the @param key was present
     */
    template<typename Type_T>
    inline bool retrieveAndStore(Json const& data, std::string_view key, Type_T& outValue, bool leaveIntact = true, Type_T defaultTo = Type_T())
    {
		bool const hasKey = data.contains(key);
        if(hasKey)
        {
            outValue = data[key].get<Type_T>();
        }
        else if(!leaveIntact)
        {
			outValue = defaultTo;
		}

		return hasKey;
	}

	/**
	 * @brief Retrieves a value of @tparam Type_T for the given @param key if present within the @param data
	 * If the key does not exist, returns @param defaultTo
	 * @return The retrieved value when available, @param defaultTo otherwise
	 */
	template<typename Type_T>
    inline Type_T retrieve(Json const& data, std::string_view key, Type_T defaultTo = Type_T())
    {
		bool const hasKey = data.contains(key);
        if(hasKey)
        {
            return data[key].get<Type_T>();
        }

		return defaultTo;
	}
}