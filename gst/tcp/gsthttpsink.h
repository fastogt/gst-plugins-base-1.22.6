/* GStreamer
 * Copyright (C) <1999> Erik Walthinsen <omega@cse.ogi.edu>
 * Copyright (C) <2004> Thomas Vander Stichele <thomas at apestaart dot org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */


#ifndef __GST_HTTP_SINK_H__
#define __GST_HTTP_SINK_H__


#include <gst/gst.h>
#include <gio/gio.h>

G_BEGIN_DECLS

#include "gstmultisocketsink.h"

#define GST_TYPE_HTTP_SINK \
  (gst_http_sink_get_type())
#define GST_HTTP_SINK(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_HTTP_SINK,GstHTTPSink))
#define GST_HTTP_SINK_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_HTTP_SINK,GstHTTPSinkClass))
#define GST_IS_HTTP_SINK(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_HTTP_SINK))
#define GST_IS_HTTP_SINK_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_HTTP_SINK))

typedef struct _GstHTTPSink GstHTTPSink;
typedef struct _GstHTTPSinkClass GstHTTPSinkClass;

typedef enum {
  GST_HTTP_SINK_OPEN             = (GST_ELEMENT_FLAG_LAST << 0),

  GST_HTTP_SINK_FLAG_LAST        = (GST_ELEMENT_FLAG_LAST << 2)
} GstHTTPSinkFlags;

/**
 * GstHTTPSink:
 *
 * Opaque data structure.
 */
struct _GstHTTPSink {
  GstMultiSocketSink element;

  /* server information */
  int current_port;        /* currently bound-to port, or 0 */ /* ATOMIC */
  int server_port;         /* port property */
  gchar *host;             /* host property */
  gchar *key;              /* key */

  GSocket *server_socket;
  GSource *server_source;
};

struct _GstHTTPSinkClass {
  GstMultiSocketSinkClass parent_class;
};

GType gst_http_sink_get_type (void);

G_END_DECLS

#endif /* __GST_HTTP_SINK_H__ */
