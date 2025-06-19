#ifndef FHEROES2_AI_CHATGPT_H
#define FHEROES2_AI_CHATGPT_H

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

#include "ai_battle.h"
#include <string>

namespace AI
{
    class ChatGPTBattleAI
    {
    public:
        static ChatGPTBattleAI & Get();

        bool isEnabled() const;

        Battle::Actions planUnitTurn( Battle::Arena & arena, const Battle::Unit & currentUnit );

    private:
        ChatGPTBattleAI();

        std::string queryOpenAI( const std::string & prompt ) const;

        std::string _apiKey;
    };
}

#endif // FHEROES2_AI_CHATGPT_H
