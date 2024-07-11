#ifndef _SARISSAMINI_SM_
#define _SARISSA_MINI_SM_

#include "unordered_map"
#include "stdexcept"
#include "exception"
#include "iostream"

class SarissaBTNode;

namespace Sarissa {
	namespace MinimalSM {
		class SarissaMinimalSM final {
		private:
			std::unordered_map< int, SarissaBTNode* > nodes_;
			std::unordered_map< int, bool > transitions_;
			int currentNodeId_;
			bool isRunning_;

		public:
			template < typename T >
			void ResistNode( T& node ) {
				int id = nodes_.size();
				SarissaBTNode* casted = static_cast< SarissaBTNode* > (T);
				if ( casted != nullptr ) {
					casted->SetId(id);
				}
			}
		};
	}
}
#endif // !_SARISSAMINI_SM_
