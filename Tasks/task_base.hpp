/*
 * tasks.h
 *
 *  Created on: Nov 25, 2023
 *      Author: giaco
 */

#ifndef TASK_BASE_HPP_
#define TASK_BASE_HPP_

namespace Tasks
{
class TaskBase
{
	public:
		TaskBase(){};
		virtual ~TaskBase(){};
		virtual void run() = 0;
	};
}

#endif /* TASKS_H_ */
