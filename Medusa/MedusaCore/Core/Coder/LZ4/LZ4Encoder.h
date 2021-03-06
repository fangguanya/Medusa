// Copyright (c) 2015 fjz13. All rights reserved.
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file.
#pragma once
#include "MedusaCorePreDeclares.h"
#ifdef MEDUSA_LZ4
#include "Core/Coder/ICoder.h"

MEDUSA_BEGIN;

class LZ4Encoder:public ICoder
{
public:
	LZ4Encoder() = default;
	LZ4Encoder(const IEventArg& e);
	~LZ4Encoder();
	using ICoder::Code;
	virtual CoderType Type()const override { return CoderType::Encoder_LZ4; }
	virtual CoderFlags Flags()const override { return CoderFlags::Block; }
	virtual size_t GuessResultSize(const IStream& input)const override;
protected:
	virtual size_t OnCode(const MemoryData& input, MemoryData& output)const override;

};

MEDUSA_END;
#endif