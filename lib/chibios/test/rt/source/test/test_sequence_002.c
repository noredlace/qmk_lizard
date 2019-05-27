/*
    ChibiOS - Copyright (C) 2006..2016 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include "hal.h"
#include "ch_test.h"
#include "test_root.h"

/**
 * @file    test_sequence_002.c
 * @brief   Test Sequence 002 code.
 *
 * @page test_sequence_002 [2] Threads Functionality
 *
 * File: @ref test_sequence_002.c
 *
 * <h2>Description</h2>
 * This sequence tests the ChibiOS/RT functionalities related to
 * threading.
 *
 * <h2>Test Cases</h2>
 * - @subpage test_002_001
 * - @subpage test_002_002
 * - @subpage test_002_003
 * - @subpage test_002_004
 * .
 */

/****************************************************************************
 * Shared code.
 ****************************************************************************/

static THD_FUNCTION(thread, p) {

  test_emit_token(*(char *)p);
}

/****************************************************************************
 * Test cases.
 ****************************************************************************/

/**
 * @page test_002_001 [2.1] Thread Sleep functionality
 *
 * <h2>Description</h2>
 * The functionality of @p chThdSleep() and derivatives is tested.
 *
 * <h2>Test Steps</h2>
 * - [2.1.1] The current system time is read then a sleep is performed
 *   for 100 system ticks and on exit the system time is verified
 *   again.
 * - [2.1.2] The current system time is read then a sleep is performed
 *   for 100000 microseconds and on exit the system time is verified
 *   again.
 * - [2.1.3] The current system time is read then a sleep is performed
 *   for 100 milliseconds and on exit the system time is verified
 *   again.
 * - [2.1.4] The current system time is read then a sleep is performed
 *   for 1 second and on exit the system time is verified again.
 * - [2.1.5] Function chThdSleepUntil() is tested with a timeline of
 *   "now" + 100 ticks.
 * .
 */

static void test_002_001_execute(void) {
  systime_t time;

  /* [2.1.1] The current system time is read then a sleep is performed
     for 100 system ticks and on exit the system time is verified
     again.*/
  test_set_step(1);
  {
    time = chVTGetSystemTimeX();
    chThdSleep(100);
    test_assert_time_window(time + 100,
                            time + 100 + CH_CFG_ST_TIMEDELTA + 1,
                            "out of time window");
  }

  /* [2.1.2] The current system time is read then a sleep is performed
     for 100000 microseconds and on exit the system time is verified
     again.*/
  test_set_step(2);
  {
    time = chVTGetSystemTimeX();
    chThdSleepMicroseconds(100000);
    test_assert_time_window(time + US2ST(100000),
                            time + US2ST(100000) + CH_CFG_ST_TIMEDELTA + 1,
                            "out of time window");
  }

  /* [2.1.3] The current system time is read then a sleep is performed
     for 100 milliseconds and on exit the system time is verified
     again.*/
  test_set_step(3);
  {
    time = chVTGetSystemTimeX();
    chThdSleepMilliseconds(100);
    test_assert_time_window(time + MS2ST(100),
                            time + MS2ST(100) + CH_CFG_ST_TIMEDELTA + 1,
                            "out of time window");
  }

  /* [2.1.4] The current system time is read then a sleep is performed
     for 1 second and on exit the system time is verified again.*/
  test_set_step(4);
  {
    time = chVTGetSystemTimeX();
    chThdSleepSeconds(1);
    test_assert_time_window(time + S2ST(1),
                            time + S2ST(1) + CH_CFG_ST_TIMEDELTA + 1,
                            "out of time window");
  }

  /* [2.1.5] Function chThdSleepUntil() is tested with a timeline of
     "now" + 100 ticks.*/
  test_set_step(5);
  {
    time = chVTGetSystemTimeX();
    chThdSleepUntil(time + 100);
    test_assert_time_window(time + 100,
                            time + 100 + CH_CFG_ST_TIMEDELTA + 1,
                            "out of time window");
  }
}

static const testcase_t test_002_001 = {
  "Thread Sleep functionality",
  NULL,
  NULL,
  test_002_001_execute
};

/**
 * @page test_002_002 [2.2] Ready List functionality, threads priority order
 *
 * <h2>Description</h2>
 * Five threads, are enqueued in the ready list and atomically
 * executed. The test expects the threads to perform their operations
 * in correct priority order regardless of the initial order.
 *
 * <h2>Test Steps</h2>
 * - [2.2.1] Creating 5 threads with increasing priority, execution
 *   sequence is tested.
 * - [2.2.2] Creating 5 threads with decreasing priority, execution
 *   sequence is tested.
 * - [2.2.3] Creating 5 threads with pseudo-random priority, execution
 *   sequence is tested.
 * .
 */

static void test_002_002_execute(void) {

  /* [2.2.1] Creating 5 threads with increasing priority, execution
     sequence is tested.*/
  test_set_step(1);
  {
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX()-5, thread, "E");
    threads[1] = chThdCreateStatic(wa[1], WA_SIZE, chThdGetPriorityX()-4, thread, "D");
    threads[2] = chThdCreateStatic(wa[2], WA_SIZE, chThdGetPriorityX()-3, thread, "C");
    threads[3] = chThdCreateStatic(wa[3], WA_SIZE, chThdGetPriorityX()-2, thread, "B");
    threads[4] = chThdCreateStatic(wa[4], WA_SIZE, chThdGetPriorityX()-1, thread, "A");
    test_wait_threads();
    test_assert_sequence("ABCDE", "invalid sequence");
  }

  /* [2.2.2] Creating 5 threads with decreasing priority, execution
     sequence is tested.*/
  test_set_step(2);
  {
    threads[4] = chThdCreateStatic(wa[4], WA_SIZE, chThdGetPriorityX()-1, thread, "A");
    threads[3] = chThdCreateStatic(wa[3], WA_SIZE, chThdGetPriorityX()-2, thread, "B");
    threads[2] = chThdCreateStatic(wa[2], WA_SIZE, chThdGetPriorityX()-3, thread, "C");
    threads[1] = chThdCreateStatic(wa[1], WA_SIZE, chThdGetPriorityX()-4, thread, "D");
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX()-5, thread, "E");
    test_wait_threads();
    test_assert_sequence("ABCDE", "invalid sequence");
  }

  /* [2.2.3] Creating 5 threads with pseudo-random priority, execution
     sequence is tested.*/
  test_set_step(3);
  {
    threads[1] = chThdCreateStatic(wa[1], WA_SIZE, chThdGetPriorityX()-4, thread, "D");
    threads[0] = chThdCreateStatic(wa[0], WA_SIZE, chThdGetPriorityX()-5, thread, "E");
    threads[4] = chThdCreateStatic(wa[4], WA_SIZE, chThdGetPriorityX()-1, thread, "A");
    threads[3] = chThdCreateStatic(wa[3], WA_SIZE, chThdGetPriorityX()-2, thread, "B");
    threads[2] = chThdCreateStatic(wa[2], WA_SIZE, chThdGetPriorityX()-3, thread, "C");
    test_wait_threads();
    test_assert_sequence("ABCDE", "invalid sequence");
  }
}

static const testcase_t test_002_002 = {
  "Ready List functionality, threads priority order",
  NULL,
  NULL,
  test_002_002_execute
};

/**
 * @page test_002_003 [2.3] Priority change test
 *
 * <h2>Description</h2>
 * A series of priority changes are performed on the current thread in
 * order to verify that the priority change happens as expected.
 *
 * <h2>Test Steps</h2>
 * - [2.3.1] Thread priority is increased by one then a check is
 *   performed.
 * - [2.3.2] Thread priority is returned to the previous value then a
 *   check is performed.
 * .
 */

static void test_002_003_execute(void) {
  tprio_t prio, p1;

  /* [2.3.1] Thread priority is increased by one then a check is
     performed.*/
  test_set_step(1);
  {
    prio = chThdGetPriorityX();
    p1 = chThdSetPriority(prio + 1);
    test_assert(p1 == prio, "unexpected returned priority level");
    test_assert(chThdGetPriorityX() == prio + 1, "unexpected priority level");
  }

  /* [2.3.2] Thread priority is returned to the previous value then a
     check is performed.*/
  test_set_step(2);
  {
    p1 = chThdSetPriority(p1);
    test_assert(p1 == prio + 1, "unexpected returned priority level");
    test_assert(chThdGetPriorityX() == prio, "unexpected priority level");
  }
}

static const testcase_t test_002_003 = {
  "Priority change test",
  NULL,
  NULL,
  test_002_003_execute
};

#if (CH_CFG_USE_MUTEXES) || defined(__DOXYGEN__)
/**
 * @page test_002_004 [2.4] Priority change test with Priority Inheritance
 *
 * <h2>Description</h2>
 * A series of priority changes are performed on the current thread in
 * order to verify that the priority change happens as expected.
 *
 * <h2>Conditions</h2>
 * This test is only executed if the following preprocessor condition
 * evaluates to true:
 * - CH_CFG_USE_MUTEXES
 * .
 *
 * <h2>Test Steps</h2>
 * - [2.4.1] Simulating a priority boost situation (prio > realprio).
 * - [2.4.2] Raising thread priority above original priority but below
 *   the boosted level.
 * - [2.4.3] Raising thread priority above the boosted level.
 * - [2.4.4] Restoring original conditions.
 * .
 */

static void test_002_004_execute(void) {
  tprio_t prio, p1;

  /* [2.4.1] Simulating a priority boost situation (prio > realprio).*/
  test_set_step(1);
  {
    prio = chThdGetPriorityX();
    chThdGetSelfX()->prio += 2;
    test_assert(chThdGetPriorityX() == prio + 2, "unexpected priority level");
  }

  /* [2.4.2] Raising thread priority above original priority but below
     the boosted level.*/
  test_set_step(2);
  {
    p1 = chThdSetPriority(prio + 1);
    test_assert(p1 == prio, "unexpected returned priority level");
    test_assert(chThdGetSelfX()->prio == prio + 2, "unexpected priority level");
    test_assert(chThdGetSelfX()->realprio == prio + 1, "unexpected returned real priority level");
  }

  /* [2.4.3] Raising thread priority above the boosted level.*/
  test_set_step(3);
  {
    p1 = chThdSetPriority(prio + 3);
    test_assert(p1 == prio + 1, "unexpected returned priority level");
    test_assert(chThdGetSelfX()->prio == prio + 3, "unexpected priority level");
    test_assert(chThdGetSelfX()->realprio == prio + 3, "unexpected real priority level");
  }

  /* [2.4.4] Restoring original conditions.*/
  test_set_step(4);
  {
    chSysLock();
    chThdGetSelfX()->prio = prio;
    chThdGetSelfX()->realprio = prio;
    chSysUnlock();
  }
}

static const testcase_t test_002_004 = {
  "Priority change test with Priority Inheritance",
  NULL,
  NULL,
  test_002_004_execute
};
#endif /* CH_CFG_USE_MUTEXES */

/****************************************************************************
 * Exported data.
 ****************************************************************************/

/**
 * @brief   Threads Functionality.
 */
const testcase_t * const test_sequence_002[] = {
  &test_002_001,
  &test_002_002,
  &test_002_003,
#if (CH_CFG_USE_MUTEXES) || defined(__DOXYGEN__)
  &test_002_004,
#endif
  NULL
};
