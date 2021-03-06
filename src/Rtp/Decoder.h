﻿/*
 * MIT License
 *
 * Copyright (c) 2020 xiongziliang <771730766@qq.com>
 *
 * This file is part of ZLMediaKit(https://github.com/xiongziliang/ZLMediaKit).
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef ZLMEDIAKIT_DECODER_H
#define ZLMEDIAKIT_DECODER_H

#if defined(ENABLE_RTPPROXY)
#include <stdint.h>
#include <memory>
#include <functional>
#include "Decoder.h"
using namespace std;
namespace mediakit {

class Decoder {
public:
    typedef std::shared_ptr<Decoder> Ptr;
    typedef enum {
        decoder_ts = 0,
        decoder_ps
    }Type;

    typedef std::function<void(int stream,int codecid,int flags,int64_t pts,int64_t dts,const void *data,int bytes)> onDecode;
    virtual int input(const uint8_t *data, int bytes) = 0;
    virtual void setOnDecode(const onDecode &decode) = 0;
    static Ptr createDecoder(Type type);
protected:
    Decoder() = default;
    virtual ~Decoder() = default;
};

}//namespace mediakit
#endif//defined(ENABLE_RTPPROXY)
#endif //ZLMEDIAKIT_DECODER_H
