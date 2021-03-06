/*
 * libAgatha library
 *
 * This file is part of the libAgatha library
 * Copyright (C) 2011 Francesco Nwokeka <francesco.nwokeka@gmail.com>
 *
 */

#include "../include/player.h"
#include "playerserializerobject.h"
#include "qjson/include/QJson/QObjectHelper"
#include "requestmaker.h"

#include <string>
#include <QtCore/QVariant>

using namespace Agatha;

RequestMaker::RequestMaker()
{
}

RequestMaker::~RequestMaker()
{
}

QByteArray RequestMaker::createRequest(const std::string &token, GameType game, RequestType type, Player *player)
{
    QByteArray request;
    QVariantMap json;

    json.insert("token", token.c_str());

    if (game == URT_411) {
        json.insert("game", "URT_411");
    }

    if (type == ADD_PLAYER) {
        json.insert("command", "add");
    } else if (type == IS_BANNED) {
        json.insert("command", "isBanned");
    } else if (type == BAN) {
        json.insert("command", "ban");
    }

    json.insert("playerInfo", QJson::QObjectHelper::qobject2qvariant(new PlayerSerializerObject(player)));

    return m_jsonSerializer.serialize(json);
}
