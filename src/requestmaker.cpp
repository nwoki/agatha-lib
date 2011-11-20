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

#include <QtCore/QVariant>

using namespace Agatha;

RequestMaker::RequestMaker()
{
}

RequestMaker::~RequestMaker()
{
}

QByteArray RequestMaker::createRequest(GameType game, RequestType type, Player *player)
{
    QByteArray request;
    QVariantMap json;

    if (game == URT_411) {
        json.insert("game", "URT_411");
    }

    if (type == IS_BANNED) {
        // TODO create ban query request
        json.insert("command", "isBanned");
    } else if (type == BAN) {
        // TODO create ban request
        json.insert("command", "ban");
    }

    json.insert("playerInfo", QJson::QObjectHelper::qobject2qvariant(new PlayerSerializerObject(player)));

    return m_jsonSerializer.serialize(json);
}
