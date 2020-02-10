#pragma once

#include <cerrno>
#include <cstring>
#include <memory>

#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>

using namespace std;

using msgbuf_t = struct msgbuf;

auto send_message(int id, const char *msg, const size_t length)
{
    const auto type = 1;
    const auto flags = 0;
    auto message = shared_ptr<msgbuf_t>{(msgbuf_t *)::operator new(sizeof(msgbuf_t) + length)};

    message->mtype = type;
    memcpy(message->mtext, msg, length);

    return msgsnd(id, message.get(), length, flags);
}
