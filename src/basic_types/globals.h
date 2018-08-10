/***************************************************************************
 *   Copyright (C) 2014 by Jan Stückrath <jan.stueckrath@uni-due.de>       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110, USA                    *
 ***************************************************************************/

#ifndef GLOBALS_H_
#define GLOBALS_H_

// include standard data structures for all classes
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <map>

// the included data structures can be used without explicit using statement
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::unordered_multiset;
using std::unique_ptr;
using std::shared_ptr;
using std::pair;
using std::make_shared;
using std::map;

// ********************************************************************************************
// As convention the name of every variable and function defined here must start with "gl_".
// This does not include type definitions!
// ********************************************************************************************

namespace uncover {

	/**
	 * IDType is an (unsigned) integer specifically used as an Identifier of graphs, elements of graphs or analysis steps.
	 */
	typedef unsigned int IDType;

	/**
	 * IDType_MAX is the largest possible value a variable of type IDType can have.
	 */
	extern const IDType IDType_MAX;

	namespace logging {

		/**
		 * LogTypes defines all types of log-messages usable with a messageLogger stream.
		 */
		enum LogTypes {
			/** No Logging is displayed. */
			LT_None = -1,
			/** Only status information of the computation is displayed. */
			LT_UserInfo = 0,
			/** Like LT_UserInfo, additionally displaying errors blocking or stopping normal computation. */
			LT_CriticalError = 1,
			/** Like LT_CriticalError, additionally displaying errors which can be ignored but probably
			 * produce unintended side effects. */
			LT_Error = 2,
			/** Like LT_Error, additionally displaying warnings. */
			LT_Warning = 3,
			/** Like LT_Warnings, additionally displaying debug messages. */
			LT_Debug = 4};

		/**
		 * Takes a log-type defined by LogTypes and returns a string representation.
		 * @param type the log-type to be converted
		 * @return a string representation for the log-type
		 */
		std::string gl_logTypeToString(LogTypes type);

		/**
		 * gl_LogLevel is the default level of log-messages streamed using the messageLogger.
		 */
		extern logging::LogTypes gl_LogLevel;

	}

	namespace graphs {

		/**
		 * PartSig is a Signature of an element of a graph. It is used as part of the Signature type.
		 */
		typedef unsigned int PartSig;

		/**
		 * HGSignature represents a Signature calculated from a Hypergraph. If two Hypergraphs are
		 * isomorphic, their signature is equal.
		 */
		typedef unordered_map<IDType,PartSig> HGSignature;

	}

	/**
	 * This method returns a new unique ID for a state of a verification instance.
	 * The ID may intersect with ID's generated by gl_getNewRuleID() and gl_getNewStepID().
	 * @return an ID not used by any other state
	 */
	IDType gl_getNewStateID();

	/**
	 * This method returns a new unique ID for a transformation rule of a verification instance.
	 * The ID may intersect with ID's generated by gl_getNewStateID() and gl_getNewStepID().
	 * @return an ID not used by any other rule
	 */
	IDType gl_getNewRuleID();

	/**
	 * This method returns a new unique ID for a single verification step of a verification instance.
	 * The ID may intersect with ID's generated by gl_getNewStateID() and gl_getNewRuleID().
	 * @return an ID not used by any other step
	 */
	IDType gl_getNewStepID();

}

#endif /* GLOBALS_H_ */