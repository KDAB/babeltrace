#ifndef BABELTRACE_GRAPH_PRIVATE_COMPONENT_CLASS_SOURCE_H
#define BABELTRACE_GRAPH_PRIVATE_COMPONENT_CLASS_SOURCE_H

/*
 * Copyright 2016 Jérémie Galarneau <jeremie.galarneau@efficios.com>
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

#include <stdint.h>

/* For enum bt_notification_array */
#include <babeltrace/graph/notification.h>

/* For enum bt_self_component_status */
#include <babeltrace/graph/self-component.h>

/* For enum bt_query_status */
#include <babeltrace/graph/query-executor.h>

/* For enum bt_self_notification_iterator_status */
#include <babeltrace/graph/self-notification-iterator.h>

/* For struct bt_private_component_class_query_method_return */
#include <babeltrace/graph/private-component-class.h>

#ifdef __cplusplus
extern "C" {
#endif

struct bt_self_component_class_source;
struct bt_component_class_source;
struct bt_self_component_source;
struct bt_private_component_class;
struct bt_private_component_class_source;
struct bt_self_component_port_output;
struct bt_port_input;
struct bt_query_executor;
struct bt_value;

typedef enum bt_self_component_status
(*bt_private_component_class_source_init_method)(
		struct bt_self_component_source *self_component,
		struct bt_value *params, void *init_method_data);

typedef void (*bt_private_component_class_source_finalize_method)(
		struct bt_self_component_source *self_component);

typedef enum bt_self_notification_iterator_status
(*bt_private_component_class_source_notification_iterator_init_method)(
		struct bt_self_notification_iterator *notification_iterator,
		struct bt_self_component_source *self_component,
		struct bt_self_component_port_output *port);

typedef void
(*bt_private_component_class_source_notification_iterator_finalize_method)(
		struct bt_self_notification_iterator *notification_iterator);

typedef enum bt_self_notification_iterator_status
(*bt_private_component_class_source_notification_iterator_next_method)(
		struct bt_self_notification_iterator *notification_iterator,
		bt_notification_array notifs, uint64_t capacity,
		uint64_t *count);

typedef enum bt_query_status
(*bt_private_component_class_source_query_method)(
		struct bt_self_component_class_source *comp_class,
		struct bt_query_executor *query_executor,
		const char *object, struct bt_value *params,
		struct bt_value **result);

typedef enum bt_self_component_status
(*bt_private_component_class_source_accept_output_port_connection_method)(
		struct bt_self_component_source *self_component,
		struct bt_self_component_port_output *self_port,
		struct bt_port_input *other_port);

typedef enum bt_self_component_status
(*bt_private_component_class_source_output_port_connected_method)(
		struct bt_self_component_source *self_component,
		struct bt_self_component_port_output *self_port,
		struct bt_port_input *other_port);

typedef void
(*bt_private_component_class_source_output_port_disconnected_method)(
		struct bt_self_component_source *self_component,
		struct bt_self_component_port_output *self_port);

static inline
struct bt_private_component_class *
bt_private_component_class_source_borrow_private_component_class(
		struct bt_private_component_class_source *priv_comp_cls_source)
{
	return (void *) priv_comp_cls_source;
}

static inline
struct bt_component_class_source *
bt_private_component_class_source_borrow_component_class_source(
		struct bt_private_component_class_source *priv_comp_cls_source)
{
	return (void *) priv_comp_cls_source;
}

extern
struct bt_private_component_class_source *
bt_private_component_class_source_create(
		const char *name,
		bt_private_component_class_source_notification_iterator_next_method method);

extern int bt_private_component_class_source_set_init_method(
		struct bt_private_component_class_source *comp_class,
		bt_private_component_class_source_init_method method);

extern int bt_private_component_class_source_set_finalize_method(
		struct bt_private_component_class_source *comp_class,
		bt_private_component_class_source_finalize_method method);

extern int bt_private_component_class_source_set_accept_output_port_connection_method(
		struct bt_private_component_class_source *comp_class,
		bt_private_component_class_source_accept_output_port_connection_method method);

extern int bt_private_component_class_source_set_output_port_connected_method(
		struct bt_private_component_class_source *comp_class,
		bt_private_component_class_source_output_port_connected_method method);

extern int bt_private_component_class_source_set_output_port_disconnected_method(
		struct bt_private_component_class_source *comp_class,
		bt_private_component_class_source_output_port_disconnected_method method);

extern int bt_private_component_class_source_set_query_method(
		struct bt_private_component_class_source *comp_class,
		bt_private_component_class_source_query_method method);

extern int bt_private_component_class_source_set_notification_iterator_init_method(
		struct bt_private_component_class_source *comp_class,
		bt_private_component_class_source_notification_iterator_init_method method);

extern int bt_private_component_class_source_set_notification_iterator_finalize_method(
		struct bt_private_component_class_source *comp_class,
		bt_private_component_class_source_notification_iterator_finalize_method method);

#ifdef __cplusplus
}
#endif

#endif /* BABELTRACE_GRAPH_PRIVATE_COMPONENT_CLASS_SOURCE_H */