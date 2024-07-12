#ifndef _SARISSAMINI_SM_
#define _SARISSA_MINI_SM_

#include "unordered_map"
#include "stdexcept"
#include "exception"
#include "iostream"

namespace Sarissa {
	namespace MinimalSM {

		// �O���錾
		class SarissaBTNode;

		class SarissaMinimalSM final {
		private:
			std::unordered_map< int, SarissaBTNode* > nodes_;
			std::unordered_map< int, bool > transitions_;
			int currentNodeId_;
			bool isRunning_;

		public:
			template < typename T >
			void ResistNode(T* node);

			template < typename T1, typename T2 >
			void ApplyTransition(T1* node1, T2* node2);

			void UpdateTransition(int id, bool condition);

			void SetCurrentNodeAs(int id);

			template < typename T >
			void SetCurrentNodeAs(T* node1);

			void StartMachine();

			void UpdateMachine();

			void EndMachine();
		};
	}
}
#endif /* !_SARISSAMINI_SM_ */
