#ifndef AK_THREAD__H
#define AK_THREAD__H

#include <pthread.h>

namespace newsbeuter {

	// TODO: implement an option to provide attributes

	class thread {
		public:
			thread();
			virtual ~thread();
			void start();
			void join();

		protected:
			virtual void run() = 0;
			void exit();
			void detached_exit();

		private:
			static void * run_thread(thread * p);
			static void cleanup(thread * p);
			pthread_t pt;
	};

}


#endif
