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

#ifndef BACKWARDANALYSISSCENARIO_H_
#define BACKWARDANALYSISSCENARIO_H_

#include "../analysis/BackwardAnalysis.h"
#include "../basic_types/Scenario.h"
#include "../graphs/GTS.h"
#include <boost/filesystem.hpp>

namespace uncover {
	namespace scenarios {

		/**
		 * This Scenario performs a backward analysis according to the provided parameters. Especially
		 * the order is variable. The given GTS has to be a well-structured transition system with respect
		 * to the chosen order.
		 * When finished, all computed error graphs are stored in the working directory of the program.
		 * @author Jan Stückrath
		 * @see analysis::BackwardAnalysis
		 */
		class BackwardAnalysisScenario : public basic_types::Scenario {

			public:

				/**
				 * Creates a new instance of this Scenario.
				 */
				BackwardAnalysisScenario();

				/**
				 * Destroys the current instance of this Scenario.
				 */
				virtual ~BackwardAnalysisScenario();

				/**
				 * Performs the backward analysis. This includes normally a preparation of the rules and performing
				 * backward steps as long as necessary. The set of resulting error graphs is written to the file
				 * system as XML document. The analysis may terminate before computing all error graphs if specified
				 * its parameters
				 */
				virtual void run() override;

			protected:

				virtual void initialize(unordered_map<string,string>& parameters) override;

				/**
				 * This BackwardAnalysis object stores all data needed for a backward search and performs the steps.
				 */
				analysis::BackwardAnalysis* backwardAnalysis;

				/**
				 * Stores the BackwardResultHandler which processes the intermediate results of the backward search.
				 */
				analysis::BackwardResultHandler_sp resultHandler;

				/**
				 * Stores the folder in which the files generated by this scenario, e.g. error graphs, will be written.
				 */
				boost::filesystem::path resultFolder;

		};

	} /* namespace scenarios */
} /* namespace uncover */

#endif /* BACKWARDANALYSIS_H_ */