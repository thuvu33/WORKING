#ifndef _GST_PJNATH_SINK_H
#define _GST_PJNATH_SINK_H

#include <gst/gst.h>
#include <gst/base/gstbasesink.h>
#include <pjlib.h>
#include <pjlib-util.h>
#include <pjnath.h>

G_BEGIN_DECLS

#define GST_TYPE_PJNATH_SINK \
  (gst_pjnath_sink_get_type())
#define GST_PJNATH_SINK(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_PJNATH_SINK,GstpjnathSink))
#define GST_PJNATH_SINK_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_PJNATH_SINK,GstpjnathSinkClass))
#define GST_IS_PJNATH_SINK(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_PJNATH_SINK))
#define GST_IS_PJNATH_SINK_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_PJNATH_SINK))

typedef struct _GstpjnathSink GstpjnathSink;

struct _GstpjnathSink
{
  GstBaseSink parent;
  GstPad *sinkpad;

  pj_ice_strans	*icest;
  guint comp_id;
  pj_sockaddr *def_addr;

};

typedef struct _GstpjnathSinkClass GstpjnathSinkClass;

struct _GstpjnathSinkClass
{
  GstBaseSinkClass parent_class;
};

GType gst_pjnath_sink_get_type (void);

G_END_DECLS

#endif
