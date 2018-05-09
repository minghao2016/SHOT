/**
   The Supporting Hyperplane Optimization Toolkit (SHOT).

   @author Andreas Lundell, Åbo Akademi University

   @section LICENSE 
   This software is licensed under the Eclipse Public License 2.0. 
   Please see the README and LICENSE files for more information.
*/

#include "TaskCheckAbsoluteGap.h"

TaskCheckAbsoluteGap::TaskCheckAbsoluteGap(EnvironmentPtr envPtr, std::string taskIDTrue) : TaskBase(envPtr), taskIDIfTrue(taskIDTrue)
{
}

TaskCheckAbsoluteGap::~TaskCheckAbsoluteGap()
{
}

void TaskCheckAbsoluteGap::run()
{
    if (env->process->isAbsoluteObjectiveGapToleranceMet())
    {
        env->process->terminationReason = E_TerminationReason::AbsoluteGap;
        env->tasks->setNextTask(taskIDIfTrue);
    }
}

std::string TaskCheckAbsoluteGap::getType()
{
    std::string type = typeid(this).name();
    return (type);
}
