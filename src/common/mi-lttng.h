/*
 * Copyright (C) 2014 - Jonathan Rajotte <jonathan.r.julien@gmail.com>
 *                    - Olivier Cotte <olivier.cotte@polymtl.ca>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License, version 2 only, as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 51
 * Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _MI_LTTNG_H
#define _MI_LTTNG_H

#include <stdint.h>

#include <common/error.h>
#include <common/macros.h>
#include <common/config/config.h>
#include <lttng/lttng.h>

/* Don't want to reference snapshot-internal.h here */
struct lttng_snapshot_output;

/* Instance of a machine interface writer. */
struct mi_writer {
	struct config_writer *writer;
	enum lttng_mi_output_type type;
};

/*
 * Version information for the machine interface.
 */
struct mi_lttng_version {
	char version[NAME_MAX]; /* Version number of package */
	uint32_t version_major; /* LTTng-Tools major version number */
	uint32_t version_minor; /* LTTng-Tools minor version number */
	uint32_t version_patchlevel; /* LTTng-Tools patchlevel version number */
	char version_commit[NAME_MAX]; /* Commit hash of the current version */
	char version_name[NAME_MAX];
	char package_url[NAME_MAX]; /* Define to the home page for this package. */
};

/* Strings related to command */
const char * const mi_lttng_element_command;
const char * const mi_lttng_element_command_action;
const char * const mi_lttng_element_command_add_context;
const char * const mi_lttng_element_command_calibrate;
const char * const mi_lttng_element_command_create;
const char * const mi_lttng_element_command_destroy;
const char * const mi_lttng_element_command_disable_channel;
const char * const mi_lttng_element_command_disable_event;
const char * const mi_lttng_element_command_enable_channels;
const char * const mi_lttng_element_command_enable_event;
const char * const mi_lttng_element_command_list;
const char * const mi_lttng_element_command_load;
const char * const mi_lttng_element_command_name;
const char * const mi_lttng_element_command_output;
const char * const mi_lttng_element_command_save;
const char * const mi_lttng_element_command_set_session;
const char * const mi_lttng_element_command_snapshot;
const char * const mi_lttng_element_command_snapshot_add;
const char * const mi_lttng_element_command_snapshot_del;
const char * const mi_lttng_element_command_snapshot_list;
const char * const mi_lttng_element_command_snapshot_record;
const char * const mi_lttng_element_command_start;
const char * const mi_lttng_element_command_stop;
const char * const mi_lttng_element_command_success;
const char * const mi_lttng_element_command_track;
const char * const mi_lttng_element_command_untrack;
const char * const mi_lttng_element_command_version;

/* Strings related to version command */
const char * const mi_lttng_element_version;
const char * const mi_lttng_element_version_commit;
const char * const mi_lttng_element_version_description;
const char * const mi_lttng_element_version_license;
const char * const mi_lttng_element_version_major;
const char * const mi_lttng_element_version_minor;
const char * const mi_lttng_element_version_patch_level;
const char * const mi_lttng_element_version_str;
const char * const mi_lttng_element_version_web;

/* String related to a lttng_event_field */
const char * const mi_lttng_element_event_field;
const char * const mi_lttng_element_event_fields;

/* String related to lttng_event_context */
const char * const mi_lttng_context_type_perf_counter;
const char * const mi_lttng_context_type_perf_cpu_counter;
const char * const mi_lttng_context_type_perf_thread_counter;

/* String related to lttng_event_perf_counter_ctx */
const char * const mi_lttng_element_perf_counter_context;

/* Strings related to pid */
const char * const mi_lttng_element_pid_tracker;
const char * const mi_lttng_element_pids;
const char * const mi_lttng_element_pid;
const char * const mi_lttng_element_pid_id;

/* Strings related to save command */
const char * const mi_lttng_element_save;

/* Strings related to load command */
const char * const mi_lttng_element_load;

/* General element of mi_lttng */
const char * const mi_lttng_element_empty;
const char * const mi_lttng_element_id;
const char * const mi_lttng_element_nowrite;
const char * const mi_lttng_element_success;
const char * const mi_lttng_element_type_enum;
const char * const mi_lttng_element_type_float;
const char * const mi_lttng_element_type_integer;
const char * const mi_lttng_element_type_other;
const char * const mi_lttng_element_type_string;

/* String related to loglevel */
const char * const mi_lttng_loglevel_str_alert;
const char * const mi_lttng_loglevel_str_crit;
const char * const mi_lttng_loglevel_str_debug;
const char * const mi_lttng_loglevel_str_debug_function;
const char * const mi_lttng_loglevel_str_debug_line;
const char * const mi_lttng_loglevel_str_debug_module;
const char * const mi_lttng_loglevel_str_debug_process;
const char * const mi_lttng_loglevel_str_debug_program;
const char * const mi_lttng_loglevel_str_debug_system;
const char * const mi_lttng_loglevel_str_debug_unit;
const char * const mi_lttng_loglevel_str_emerg;
const char * const mi_lttng_loglevel_str_err;
const char * const mi_lttng_loglevel_str_info;
const char * const mi_lttng_loglevel_str_notice;
const char * const mi_lttng_loglevel_str_unknown;
const char * const mi_lttng_loglevel_str_warning;

/* String related to loglevel JUL */
const char * const mi_lttng_loglevel_str_jul_all;
const char * const mi_lttng_loglevel_str_jul_config;
const char * const mi_lttng_loglevel_str_jul_fine;
const char * const mi_lttng_loglevel_str_jul_finer;
const char * const mi_lttng_loglevel_str_jul_finest;
const char * const mi_lttng_loglevel_str_jul_info;
const char * const mi_lttng_loglevel_str_jul_off;
const char * const mi_lttng_loglevel_str_jul_severe;
const char * const mi_lttng_loglevel_str_jul_warning;

/* String related to loglevel Log4j */
const char * const mi_lttng_loglevel_str_log4j_off;
const char * const mi_lttng_loglevel_str_log4j_fatal;
const char * const mi_lttng_loglevel_str_log4j_error;
const char * const mi_lttng_loglevel_str_log4j_warn;
const char * const mi_lttng_loglevel_str_log4j_info;
const char * const mi_lttng_loglevel_str_log4j_debug;
const char * const mi_lttng_loglevel_str_log4j_trace;
const char * const mi_lttng_loglevel_str_log4j_all;

/* String related to loglevel Python */
const char * const mi_lttng_loglevel_str_python_critical;
const char * const mi_lttng_loglevel_str_python_error;
const char * const mi_lttng_loglevel_str_python_warning;
const char * const mi_lttng_loglevel_str_python_info;
const char * const mi_lttng_loglevel_str_python_debug;
const char * const mi_lttng_loglevel_str_python_notset;

/* String related to loglevel type */
const char * const mi_lttng_loglevel_type_all;
const char * const mi_lttng_loglevel_type_range;
const char * const mi_lttng_loglevel_type_single;
const char * const mi_lttng_loglevel_type_unknown;

/* Sting related to lttng_calibrate */
const char * const mi_lttng_element_calibrate;
const char * const mi_lttng_element_calibrate_function;

/* String related to a lttng_snapshot */
const char * const mi_lttng_element_snapshot_ctrl_url;
const char * const mi_lttng_element_snapshot_data_url;
const char * const mi_lttng_element_snapshot_max_size;
const char * const mi_lttng_element_snapshot_n_ptr;
const char * const mi_lttng_element_snapshot_session_name;
const char * const mi_lttng_element_snapshots;

/* Utility string function  */
const char *mi_lttng_loglevel_string(int value, enum lttng_domain_type domain);
const char *mi_lttng_logleveltype_string(enum lttng_loglevel_type value);
const char *mi_lttng_eventfieldtype_string(enum lttng_event_field_type value);
const char *mi_lttng_domaintype_string(enum lttng_domain_type value);
const char *mi_lttng_buffertype_string(enum lttng_buffer_type value);
const char *mi_lttng_calibratetype_string(enum lttng_calibrate_type val);

/*
 * mi_lttng_writer_create - Create an instance of a machine interface writer.
 *
 * @fd_output:      File to which the XML content must be written. The file will
 *                  be closed once the mi_writer has been destroyed.
 * @mi_output_type: The type of mi output
 *
 * Returns an instance of a machine interface writer on success, NULL on
 * error.
 */
struct mi_writer *mi_lttng_writer_create(int fd_output, int mi_output_type);

/*
 * mi_lttng_writer_destroy - Destroy an instance of a machine interface writer.
 *
 * @writer: An instance of a machine interface writer.
 *
 * Returns zero if the XML document could be closed cleanly. Negative values
 * indicate an error.
 */
int mi_lttng_writer_destroy(struct mi_writer *writer);

/*
 * mi_lttng_writer_command_open - Open a command tag and add it's name node.
 *
 * @writer:  An instance of a machine interface writer.
 * @command: The command name.
 *
 * Returns zero if the XML document could be closed cleanly.
 * Negative values indicate an error.
 */
int mi_lttng_writer_command_open(struct mi_writer *writer, const char *command);

/*
 * mi_lttng_writer_command_close - Close a command tag.
 *
 * @writer: An instance of a machine interface writer.
 *
 * Returns zero if the XML document could be closed cleanly.
 * Negative values indicate an error.
 */
int mi_lttng_writer_command_close(struct mi_writer *writer);

/*
 * mi_lttng_writer_open_element - Open an element tag.
 *
 * @writer:       An instance of a machine interface writer.
 * @element_name: Element tag name.
 *
 * Returns zero if the XML document could be closed cleanly.
 * Negative values indicate an error.
 */
int mi_lttng_writer_open_element(struct mi_writer *writer,
		const char *element_name);

/*
 * mi_lttng_writer_close_element - Close the current element tag.
 *
 * @writer: An instance of a machine interface writer.
 *
 * Returns zero if the XML document could be closed cleanly.
 * Negative values indicate an error.
 */
int mi_lttng_writer_close_element(struct mi_writer *writer);

/*
 * mi_lttng_close_multi_element - Close multiple element.
 *
 * @writer:     An instance of a machine interface writer.
 * @nb_element: Number of elements.
 *
 * Returns zero if the XML document could be closed cleanly.
 * Negative values indicate an error.
 */
int mi_lttng_close_multi_element(struct mi_writer *writer,
		unsigned int nb_element);

/*
 * mi_lttng_writer_write_element_unsigned_int - Write an element of type
 *                                              unsigned int.
 *
 * @writer:       An instance of a machine interface writer.
 * @element_name: Element name.
 * @value:        Unsigned int value of the element
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_writer_write_element_unsigned_int(struct mi_writer *writer,
		const char *element_name, uint64_t value);

/*
 * mi_lttng_writer_write_element_signed_int - Write an element of type
 *                                            signed int.
 *
 * @writer:       An instance of a machine interface writer.
 * @element_name: Element name.
 * @value:        Signed int value of the element.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_writer_write_element_signed_int(struct mi_writer *writer,
		const char *element_name, int64_t value);

/*
 * mi_lttng_writer_write_element_bool - Write an element of type boolean.
 *
 * @writer:       An instance of a machine interface writer.
 * @element_name: Element name.
 * @value:        Boolean value of the element.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_writer_write_element_bool(struct mi_writer *writer,
		const char *element_name, int value);

/*
 * mi_lttng_writer_write_element_string - Write an element of type string.
 *
 * @writer:       An instance of a machine interface writer.
 * @element_name: Element name.
 * @value:        String value of the element.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_writer_write_element_string(struct mi_writer *writer,
		const char *element_name, const char *value);

/*
 * mi_lttng_version - MI represention of struct version.
 *
 * @writer:            An instance of a machine interface writer.
 * @version:           Version struct.
 * @lttng_description: String value of the version description.
 * @lttng_license:     String value of the version license.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_version(struct mi_writer *writer, struct mi_lttng_version *version,
		const char *lttng_description, const char *lttng_license);

/*
 * mi_lttng_sessions_open - Open a sessions element.
 *
 * @writer: An instance of a machine interface writer.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_sessions_open(struct mi_writer *writer);

/*
 * mi_lttng_session - MI represention of struct session.
 *
 * @writer:  An instance of a machine interface writer.
 * @session: An instance of a session.
 * @is_open: Defines whether or not the session element shall be closed.
 *           This should be used carefully and the client
 *           must close the session element.
 *           Use case: nested additional information on a session
 *            ex: domain,channel event.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_session(struct mi_writer *writer,
		struct lttng_session *session, int is_open);

/*
 * mi_lttng_domains_open - Open a domains element.
 *
 * @writer: An instance of a machine interface writer.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_domains_open(struct mi_writer *writer);

/*
 * mi_lttng_domain - MI represention of struct domain.
 *
 * @writer: An instance of a machine interface writer.
 * @domain: An instance of a domain.
 *
 * @is_open: Defines whether or not the session element shall be closed.
 *           This should be used carefully and the client
 *           must close the domain element.
 *           Use case: nested addition information on a domain
 *            ex: channel event.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_domain(struct mi_writer *writer,
		struct lttng_domain *domain, int is_open);

/*
 * mi_lttng_channels_open - Open a channels element.
 *
 * @writer: An instance of a machine interface writer.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_channels_open(struct mi_writer *writer);

/*
 * mi_lttng_channel - Mi represention of struct channel.
 *
 * @writer:  An instance of a machine interface writer.
 * @channel: An instance of a channel.
 *
 * @is_open: Defines whether or not the session element shall be closed.
 *           This should be used carefully and the client
 *           must close the channel element.
 *           Use case: nested addition information on a channel.
 *            ex: channel event.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_channel(struct mi_writer *writer,
		struct lttng_channel *channel, int is_open);

/*
 * mi_lttng_channel_attr - MI representation of struct channel_attr.
 *
 * @writer: An instance of a machine interface writer.
 * @attr:   An instance of a channel_attr struct.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_channel_attr(struct mi_writer *writer,
		struct lttng_channel_attr *attr);

/*
 * mi_lttng_event_common_attributes - MI representation for event common
 *                                    attributes.
 *
 * @writer: An instance of a mi writer.
 * @event:  Single trace event.
 *
 * The common attribute are:
 * - mi event element
 * - event name
 * - event type
 * - enabled tag
 * - event filter
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_event_common_attributes(struct mi_writer *writer,
		struct lttng_event *event);

/*
 * mi_lttng_event_tracepoint_loglevel - MI representation for kernel tracepoint
 *                                      event with a loglevel.
 *
 * @writer: An instance of a mi writer.
 * @event:  Single trace event.
 * @domain: Event's domain
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_event_tracepoint_loglevel(struct mi_writer *writer,
		struct lttng_event *event, enum lttng_domain_type domain);

/*
 * mi_lttng_event_tracepoint_no_loglevel - MI representation for kernel
 *                                         tracepoint event with no loglevel.
 *
 * @writer: An instance of a mi writer.
 * @event:  Single trace event.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_event_tracepoint_no_loglevel(struct mi_writer *writer,
		struct lttng_event *event);

/*
 * mi_lttng_event_function_probe - MI representation for kernel function and
 *                                 probe event.
 *
 * @writer: An instance of a mi writer.
 * @event:  Single trace event.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_event_function_probe(struct mi_writer *writer,
		struct lttng_event *event);

/*
 * mi_lttng_event_function_entry - MI representation for kernel function entry
 *                                 event.
 *
 * @writer: An instance of a mi writer.
 * @event: Single trace event.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_event_function_entry(struct mi_writer *writer,
		struct lttng_event *event);

/*
 * mi_lttng_events_open - Open an events element.
 *
 * @writer: An instance of a machine interface writer.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_events_open(struct mi_writer *writer);

/*
 * mi_lttng_event - MI representation of an event.
 *
 * @writer:  An instance of a mi writer.
 * @event:   Single trace event.
 * @is_open: Defines whether or not the session element shall be closed.
 *           This should be used carefully and the client
 *           must close the event element.
 *           Use case: nested additional information
 * @domain:  Event's domain
 *
 * The trace event type currently supported are:
 *  TRACEPOINT,
 *  PROBE,
 *  FUNCTION,
 *  FUNCTION_ENTRY,
 *  SYSCALL
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_event(struct mi_writer *writer, struct lttng_event *event,
		int is_open, enum lttng_domain_type domain);

/*
 * mi_lttng_event_field - MI representation for struct lttng_event_field.
 *
 * @writer: An instance of a mi writer.
 * @field:  An event_field instance.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_event_field(struct mi_writer *writer,
		struct lttng_event_field *field);

/*
 * mi_lttng_event_fields_open - Open an event_fields element.
 *
 * @writer: An instance of a machine interface writer.
 *
 * Returns zero if the element have be written.
 * Negative values indicate an error.
 */
int mi_lttng_event_fields_open(struct mi_writer *writer);

/*
 * mi_lttng_pid_tracker_open - Open a pid_tracker element.
 *
 * @writer:  An instance of a machine interface writer.
 * @enabled: Tell if the pid tracker is enabled (enabled > 0)
 *
 * Note: A PIDs element is also open per definition of the tracker
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_pid_tracker_open(struct mi_writer *writer, uint32_t enabled);

/*
 * mi_lttng_pids_open - Open a PIDs element.
 *
 * @writer: An instance of a machine interface writer.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_pids_open(struct mi_writer *writer);

/*
 * mi_lttng_pid - MI representation of a PID.
 *
 * @writer:  An instance of a machine interface writer.
 * @pid:     A PID.
 *
 * @is_open: Defines whether or not the session element shall be closed.
 *           This should be used carefully and the client
 *           must close the pid element.
 *           Use case: nested addition information on a domain
 *            ex: channel event.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_pid(struct mi_writer *writer, pid_t pid , const char *cmdline,
		int is_open);

/*
 * mi_lttng_calibrate - MI representation for struct lttng_calibrate.
 *
 * @writer:    An instance of a machine interface writer.
 * @calibrate: A lttng_calibrate instance.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_calibrate(struct mi_writer *writer,
		struct lttng_calibrate *calibrate);

/*
 * mi_lttng_context - MI representation of a context.
 *
 * @writer:  An instance of a machine interface writer
 * @context: An instance of a lttng_event_context
 *
 * @is_open: Define if we close the context element
 *           This should be used carefully and the client
 *           need to close the context element.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_context(struct mi_writer *writer,
		struct lttng_event_context *context, int is_open);

/*
 * mi_lttng_perf_counter_context - MI representation of a perf_counter_context.
 *
 * @writer:  An instance of a machine interface writer
 * @contest: An instance of a lttng_event_perf_counter_ctx
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_perf_counter_context(struct mi_writer *writer,
		struct lttng_event_perf_counter_ctx  *perf_context);

/*
 * mi_lttng_snapshot_output_session_name - MI representation of the snapshot
 *                                         list_output.
 *
 * @writer:       An instance of a machine interface writer.
 * @session_name: Snapshot output for session "session_name".
 *
 * It specifies the session for which we are listing snapshots,
 * and it opens a snapshots element to list a sequence
 * of snapshots.
 *
 * Note: The client has to close the session and the snapshots elements after
 * having listed every lttng_snapshot_output.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_snapshot_output_session_name(struct mi_writer *writer,
		const char *session_name);

/*
 * mi_lttng_snapshot_list_output - MI representation of the snapshot output.
 *
 * @writer: An instance of a machine interface writer.
 * @output: A list of lttng_snapshot_output.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_snapshot_list_output(struct mi_writer *writer,
		struct lttng_snapshot_output *output);

/*
 * mi_lttng_snapshot_del_output - MI representation of the output of command
 *                                snapshot del output.
 *
 * @writer:               An instance of a machine interface writer.
 * @id:                   ID of the snapshot output.
 * @name:                 Name of the snapshot.
 * @current_session_name: Session to which the snapshot belongs.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_snapshot_del_output(struct mi_writer *writer, int id,
		const char *name, const char *current_session_name);

/*
 * mi_lttng_snapshot_add_output - MI representation of command snapshot add output
 *
 * @writer:               An instance of a machine interface writer.
 * @current_session_name: Session to which the snapshot belongs.
 * @n_ptr:                Name of the current output
 * @output:               Current output
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 * TODO MI: Remove the n_ptr argument which is in the end present inside the
 *          lttng_snapshot_output struct
 */
int mi_lttng_snapshot_add_output(struct mi_writer *writer,
		const char *current_session_name, const char *n_ptr,
		struct lttng_snapshot_output *output);

/*
 * mi_lttng_snapshot_record - MI representation of the output of the
 *                            command snapshot record from a URL (if given).
 *
 * @writer:               An instance of a machine interface writer.
 * @current_session_name: Name of the session.
 * @ctrl_url, data_url:   Destination of the output.
 *
 * Returns zero if the element's value could be written.
 * Negative values indicate an error.
 */
int mi_lttng_snapshot_record(struct mi_writer *writer,
		const char *current_session_name, const char *url,
		const char *cmdline_ctrl_url, const char *cmdline_data_url);

#endif /* _MI_LTTNG_H */
