#pragma once
#include "pch.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#ifdef _MSC_VER
#include <Windows.h>
#endif

#ifndef _MSC_VER
#define HCURSOR int
#endif

/**
 * @brief class that contains one type of windows cursors
 */
class cursor
{
public:
	enum TYPE //!< type of the cursor
	{
		WAIT,
		TEXT,
		NORMAL,
		HAND
	};

	/**
	 * @brief cursor constructor
	 *
	 * Initialises cursor handler.
	 *
	 * @param t - type of the cursor
	 */
	cursor (const TYPE t);

	void Set (const sf::WindowHandle & aWindowHandle) const; //!< set current cursor

private:
	HCURSOR Cursor; //!< windows cursor handle
};
