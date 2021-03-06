#ifndef BABELTRACE_TRACE_IR_FIELD_WRAPPER_INTERNAL_H
#define BABELTRACE_TRACE_IR_FIELD_WRAPPER_INTERNAL_H

/*
 * Copyright 2018 Philippe Proulx <pproulx@efficios.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <babeltrace/trace-ir/field-internal.h>
#include <babeltrace/object-pool-internal.h>
#include <babeltrace/object-internal.h>

struct bt_field_wrapper {
	struct bt_object base;

	/* Owned by this */
	struct bt_field *field;
};

BT_HIDDEN
struct bt_field_wrapper *bt_field_wrapper_new(void *data);

BT_HIDDEN
void bt_field_wrapper_destroy(struct bt_field_wrapper *field);

BT_HIDDEN
struct bt_field_wrapper *bt_field_wrapper_create(
		struct bt_object_pool *pool, struct bt_field_class *fc);

#endif /* BABELTRACE_TRACE_IR_FIELD_WRAPPER_INTERNAL_H */
