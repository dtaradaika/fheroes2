#include "ai_chatgpt.h"
#include <cstdlib>
#include <iostream>

/***************************************************************************
 *   fheroes2: https://github.com/ihhub/fheroes2                           *
 *   Copyright (C) 2025                                                    *
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
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

namespace AI
{
    ChatGPTBattleAI & ChatGPTBattleAI::Get()
    {
        static ChatGPTBattleAI instance;
        return instance;
    }

    ChatGPTBattleAI::ChatGPTBattleAI()
    {
        const char * key = std::getenv( "CHATGPT_API_KEY" );
        if ( key )
            _apiKey = key;
    }

    bool ChatGPTBattleAI::isEnabled() const
    {
        return !_apiKey.empty();
    }

    std::string ChatGPTBattleAI::queryOpenAI( const std::string & prompt ) const
    {
        (void)prompt;
        // Placeholder for actual network request to the OpenAI API.
        std::cerr << "ChatGPT API call would be executed here." << std::endl;
        return {};
    }

    Battle::Actions ChatGPTBattleAI::planUnitTurn( Battle::Arena & arena, const Battle::Unit & currentUnit )
    {
        if ( !isEnabled() )
            return {};

        // Build a textual representation of the battle state to send as a prompt.
        (void)arena;
        (void)currentUnit;
        queryOpenAI( "Describe the best move" );

        // TODO: parse the response and convert it into in-game actions.
        return {};
    }
}
