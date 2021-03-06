/*
 * Discriminator.hpp
 *
 *  Created on: Oct 2, 2015
 *      Author: fabricio
 */

#ifndef DISCRIMINATOR_HPP_
#define DISCRIMINATOR_HPP_

#include "./Memory.hpp"
#include <vector>
 

namespace wann
{
	class Discriminator
	{
		public:
			Discriminator(int retinaLength, 
						  int numBits, 
						  std::vector<int> memoryAddressMapping, 
						  bool isCummulative = true, 
						  bool ignoreZeroAddr = false);

			~Discriminator(void);

			void addTrainning(const std::vector<int> &retina);
			std::vector<int> predict(const std::vector<int> &retina);

		private:
			int retinaLength;
			int numBitsAddr;
			int numMemories;
			bool isCummulative;
			bool ignoreZeroAddr;
			std::vector<Memory *> memories;
			std::vector<int> memoryAddressMapping;

			Memory * getMemory(int addr);
	};

}

#endif /* DISCRIMINATOR_HPP_ */
