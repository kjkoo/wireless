/*
 * Copyright (c) 2012 Jonathan Perry
 * This code is released under the MIT license (see LICENSE file).
 */
#pragma once

#include <string>
#include <vector>

#include "util/MTRand.h"

using std::string;
using std::vector;


class CrcPacketGenerator
{
public:
	/**
	 * C'tor
	 * @param packetLengthBits the length of the packet, in bits. Must be not smaller than 40.
	 */
	CrcPacketGenerator(unsigned int packetLengthBits);

	/**
	 * Seed the pseudo-random number generator
	 * @param seedValue the seed
	 */
	void seed(unsigned int* const seed, int seedSize);

	/**
	 * Generates a packet.
	 *
	 * The produced packets have CRC32 as first 4 bytes.
	 */
	string get();

private:
	// packet length, in bytes, of the desired packet
	unsigned int m_packetLengthBits;

	// random number generator
	MTRand m_random;
};

