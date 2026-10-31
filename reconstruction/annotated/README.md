# Readable reference firmware

Generated companion to the raw rc-102 4.14 export. Original operators, types,
control flow, strings and decompiler warnings remain unchanged. Reviewed names
are descriptive; the other functions remain explicitly unresolved in `index.json`.

For compilable implementations, see [leaf routines](../rc102_leaf.c) and
[floating-point predicate](../calibration.c). This export is not a source build.

| Address | Named function | Observed behavior |
| --- | --- | --- |
| `0x0801022e` | [object_set_active_flags_0801022e](rc102.c#L87) | Set byte fields +0x18 and +0x1c and the shared +0x1d flag to one. |
| `0x08010242` | [object_clear_active_flags_and_schedule_08010242](rc102.c#L107) | Clear the same object/shared flags and schedule with delay argument 0xf0000. |
| `0x08010262` | [object_signal_and_activate_if_pending_08010262](rc102.c#L128) | If byte +0x1d is set, enqueue code 0x1009 and activate the object. |
| `0x08014898` | [dispatch_and_read_result_field_08014898](rc102.c#L2798) | Call the dispatcher and return context word +0x10. |
| `0x080148d6` | [context_set_flag_1a_080148d6](rc102.c#L2839) | Store one in the context field at offset 0x1a. |
| `0x080148de` | [context_clear_flag_pair_1a_080148de](rc102.c#L2857) | Store zero in the context field at offset 0x1a..0x1b. |
| `0x0801596c` | [worker_set_flag_09_0801596c](rc102.c#L3400) | Store one in the context field at offset 9. |
| `0x08015976` | [worker_clear_flag_09_08015976](rc102.c#L3418) | Store zero in the context field at offset 9. |
| `0x080148e6` | [context_latch_pending_and_signal_080148e6](rc102.c#L2875) | Enqueue 0x1009 when +0x1c is set and +0x1d is clear, then set +0x1d. |
| `0x08015a0e` | [shared_context_write_flag_1d_08015a0e](rc102.c#L3492) | Store the supplied byte at shared-context offset 0x1d. |
| `0x08015a20` | [shared_context_write_flag_1c_08015a20](rc102.c#L3520) | Store the supplied byte at shared-context offset 0x1c. |
| `0x08015a28` | [shared_context_write_flag_1e_08015a28](rc102.c#L3538) | Store the supplied byte at shared-context offset 0x1e. |
| `0x08015a72` | [shared_context_write_flag_20_08015a72](rc102.c#L3594) | Store the supplied byte at shared-context offset 0x20. |
| `0x08015e92` | [write_shared_byte_08015e92](rc102.c#L4051) | Store one byte through the global pointer literal at 0x08016008. |
| `0x08015ede` | [set_shared_flag_pair_08015ede](rc102.c#L4109) | Set bytes zero and four in the shared flag block to one. |
| `0x08015eec` | [select_clamped_u16_table_entry_08015eec](rc102.c#L4131) | Clamp an unsigned index to 3 and store a zero-extended 16-bit table entry at context +0x24c. |
| `0x0801609e` | [initialize_interval_and_schedule_now_0801609e](rc102.c#L4378) | Set word +0x10 to 60 and invoke the scheduling helper with delay zero. |
| `0x080165cc` | [clear_object_state_fields_080165cc](rc102.c#L4815) | Zero words +0x18/+0x1c and byte +0x20; leave other fields untouched. |
| `0x08016664` | [clear_object_bit_18_08016664](rc102.c#L4877) | Clear a selected bit in word +0x18. |
| `0x0801675c` | [schedule_object_relative_0801675c](rc102.c#L5008) | Store current ticks plus delay at object +8 and pass the object through two queue helpers. |
| `0x080167f6` | [configure_nonzero_interval_and_schedule_080167f6](rc102.c#L5107) | Ignore zero intervals; otherwise store words +0x14/+0x10 and schedule the object. |
| `0x08016834` | [queue_handle_is_present_08016834](rc102.c#L5158) | Return whether the global queue handle is non-null. |
| `0x0801683e` | [read_queue_head_deadline_0801683e](rc102.c#L5175) | Read word +8 from the object addressed by the global queue handle. |
| `0x08016858` | [event_ring_reset_indices_08016858](rc102.c#L5192) | Reset both event-ring indices at offsets +0x20/+0x24 to zero. |
| `0x08016862` | [event_ring_try_push_08016862](rc102.c#L5214) | Advance the write index modulo 16; return 1 if full, otherwise store a 16-bit event and return 0. |
| `0x080168a0` | [event_ring_has_pending_080168a0](rc102.c#L5266) | Return whether the read and write indices differ. |
| `0x080169e8` | [clear_object_flag_04_080169e8](rc102.c#L5562) | Clear byte +4 through the global context pointer. |
| `0x08016d30` | [update_selected_low_halfword_08016d30](rc102.c#L5812) | Use a byte offset table to select a word, retain its upper 16 bits, and OR in the supplied value. |
| `0x08016d98` | [read_stable_counter16_with_offset_08016d98](rc102.c#L5898) | Read the low 16 bits until two consecutive reads match, add a shared offset, and wrap to 16 bits. |
| `0x08017624` | [set_transfer_mode_and_refresh_08017624](rc102.c#L6526) | Write mode byte +0x11, obtain a refresh value, and call the refresh helper. |
| `0x08017bb0` | [read_transfer_table_halfword_08017bb0](rc102.c#L6660) | Read a halfword from transfer-state offset +0x34 plus index*2. |
| `0x08017e9e` | [invoke_optional_transfer_callback_08017e9e](rc102.c#L6909) | Invoke the callback at transfer-state offset +0x74 when non-null. |
| `0x08017eaa` | [read_transfer_mode_08017eaa](rc102.c#L6932) | Return transfer-state byte +0x11. |
| `0x08017eb4` | [transfer_positions_allow_progress_08017eb4](rc102.c#L6949) | Compare signed words +0x50 and +0x54; modes 2/4/6 permit equality, other modes require strict less-than. |
| `0x0802abf8` | [coefficient_triplet_passes_bounds_0802abf8](rc102.c#L30990) | Check three binary32 coefficients and a polynomial evaluated at 256. |
| `0x08038800` | [read_indirect_halfword_10_08038800](rc102.c#L39543) | Return halfword +0x10 from the object reached through a global pointer. |
| `0x08038a58` | [initialize_clock_register_block_08038a58](rc102.c#L39590) | Initialize the register block using the masks and ordering shown in the original instructions. |
| `0x0803961c` | [increment_and_wrap_object_value_0803961c](rc102.c#L39620) | Add an increment to word +0x18; wrap to the lower virtual-method bound when the upper bound is exceeded. |
| `0x0803974c` | [decrement_and_wrap_object_value_0803974c](rc102.c#L39646) | Subtract a decrement from word +0x18; wrap to the upper virtual-method bound when below the lower bound. |
| `0x0803a560` | [walk_relative_initialization_records_0803a560](rc102.c#L39672) | Invoke a record-relative function pointer and use its return value as the next record. |
| `0x0803a978` | [enable_coprocessor_access_with_barriers_0803a978](rc102.c#L39696) | Set CPACR bits 20..23, execute DSB/ISB, and return 0x02000000. |
| `0x0803aec8` | [call_relative_function_table_0803aec8](rc102.c#L39810) | Call each entry-relative function address from cursor up to end. |
| `0x0803ba70` | [application_reset_entry_0803ba70](rc102.c#L39871) | Set MSP when privileged, then invoke the two vector/literal-resolved startup targets. |
| `0x0803c4d8` | [trap_forever_0803c4d8](rc102.c#L39993) | Loop forever with no observable work. |
| `0x0801f3b4` | [read_nonnegative_context_index_0801f3b4](rc102.c#L14800) | Read signed byte +0x14 and clamp negative values to zero. |
| `0x0801f3c2` | [read_context_index_with_positive_bias_0801f3c2](rc102.c#L14823) | Add ten to nonnegative byte +0x14 values; preserve negative values. |
| `0x0801f3d0` | [get_shared_context_address_0801f3d0](rc102.c#L14846) | Return the shared-context pointer literal. |
| `0x0801f900` | [read_defaultable_object_byte_1_0801f900](rc102.c#L15064) | Use the default object when null, then return byte at offset +1. |
| `0x0801f908` | [read_defaultable_object_halfword_2_0801f908](rc102.c#L15084) | Use the default object when null, then return halfword at offset +2. |
| `0x0801f910` | [read_defaultable_object_halfword_8_0801f910](rc102.c#L15104) | Use the default object when null, then return halfword at offset +8. |
| `0x0801fa2c` | [apply_and_cache_bound_word_0801fa2c](rc102.c#L15263) | If source pointer +0x0c is non-null, pass its word to 0x0802bcb0 and cache it at +8. |
| `0x0801fa88` | [apply_and_cache_bound_word_0801fa88](rc102.c#L15335) | If source pointer +0x0c is non-null, pass its word to 0x0802bda0 and cache it at +8. |
| `0x0801fd3c` | [apply_and_cache_bound_word_0801fd3c](rc102.c#L15573) | If source pointer +0x0c is non-null, pass its word to 0x0802be1c and cache it at +8. |
| `0x0801fa42` | [apply_bound_word_if_changed_0801fa42](rc102.c#L15287) | Compare a non-null bound word with cache +8; invoke 0x0802bcb0 and update cache only on change. |
| `0x0801fb7c` | [apply_bound_word_if_changed_0801fb7c](rc102.c#L15422) | Compare a non-null bound word with cache +8; invoke 0x0802bda0 and update cache only on change. |
| `0x0801fdba` | [apply_bound_word_if_changed_0801fdba](rc102.c#L15628) | Compare a non-null bound word with cache +8; invoke 0x0802be1c and update cache only on change. |
| `0x0801ffec` | [apply_indexed_word_if_changed_0801ffec](rc102.c#L15901) | Use the bound byte as an index into a word table; invoke helpers and cache only if the selected word changed. |
| `0x080203f8` | [initialize_callback_state_080203f8](rc102.c#L16196) | Clear selected status/callback words and initialize two interval fields to 1000. |
| `0x0802041a` | [drain_two_slot_callback_queue_0802041a](rc102.c#L16227) | Disable interrupts while shifting callback slots, then invoke each non-null callback with interrupts enabled. |
