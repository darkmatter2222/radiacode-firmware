# Full firmware decompilation, reconstruction, recompilation, and re-upload plan

**Target outcome:** make intentional changes to recovered source, reproducibly compile them, construct a device-compatible firmware artifact, install it on the identified device, verify the intended behavior and unaffected functions, and restore the original state through a demonstrated recovery route when necessary.

**Status:** reconstruction in progress. This document is the implementation and acceptance specification for reaching that outcome. It is not a claim that the outcome has been achieved, a complete source decompile, or a currently executable installation recipe.

**Evidence baseline:** repository commit `f362bb074797f0d55a066f080335ca6ba532f23a`, reviewed November 1, 2026. Counts below describe that baseline. Later JSON reports and their source/image hashes must be inspected before relying on them. A later date or larger count alone does not make evidence stronger.

**Reference reconstruction target:** `rc-102/hw1-fw4.14`. Other registered models/builds require their own applicability, layout, hardware and deployment evidence. Do not transfer absolute addresses or device assumptions between targets.

**Current deployment state:** blocked. The CLI has no implemented device firmware writer, complete device readback, or automatic restore. Emulator allocations are not approved physical flash locations. No procedure can honestly promise that experimental firmware installation is impossible to brick.

## Contents

1. [Define completion and the two development routes](#1-define-completion-and-the-two-development-routes)
2. [Current implementation and evidence](#2-current-implementation-and-evidence)
3. [Complete remaining-work register](#3-complete-remaining-work-register)
4. [Repository rules and artifact organization](#4-repository-rules-and-artifact-organization)
5. [Reproduce the current offline baseline](#5-reproduce-the-current-offline-baseline)
6. [Establish exact device identity and hardware](#6-establish-exact-device-identity-and-hardware)
7. [Acquire, preserve and qualify recovery materials](#7-acquire-preserve-and-qualify-recovery-materials)
8. [Reverse-engineer bootloader and update requirements](#8-reverse-engineer-bootloader-and-update-requirements)
9. [Extract and map the original firmware](#9-extract-and-map-the-original-firmware)
10. [Recover functions, types, globals and control flow](#10-recover-functions-types-globals-and-control-flow)
11. [Reconstruct source and build contracts](#11-reconstruct-source-and-build-contracts)
12. [Design independent behavioral validation](#12-design-independent-behavioral-validation)
13. [Extend subsystem and whole-system coverage](#13-extend-subsystem-and-whole-system-coverage)
14. [Integrate compiled replacements safely](#14-integrate-compiled-replacements-safely)
15. [Construct and verify a device update package](#15-construct-and-verify-a-device-update-package)
16. [Implement the device transaction and recovery workflow](#16-implement-the-device-transaction-and-recovery-workflow)
17. [Run the controlled hardware program](#17-run-the-controlled-hardware-program)
18. [Complete the full-source application rebuild](#18-complete-the-full-source-application-rebuild)
19. [Evidence gates, CI and release records](#19-evidence-gates-ci-and-release-records)
20. [Execution order and ownership](#20-execution-order-and-ownership)
21. [Instructions for an AI connected to the device](#21-instructions-for-an-ai-connected-to-the-device)
22. [Failure handling and stop conditions](#22-failure-handling-and-stop-conditions)
23. [Final acceptance checklist](#23-final-acceptance-checklist)
24. [Repository references and terminology](#24-repository-references-and-terminology)

## 1. Define completion and the two development routes

### 1.1 Route A: the first verified source modification

Preserve most vendor application bytes and replace one reviewed function or a small coherent command chain with compiled source. This is a hybrid build. It is the nearer-term route to demonstrating the requested edit/build/install workflow.

Completion requires all of the following:

- A precisely specified observable change, including what behavior should remain unchanged.
- A recovered implementation whose unchanged behavior has been compared with the original machine code under documented assumptions.
- Tests of the intentional changed behavior against its own specification. The modified behavior must not be mislabeled equivalent to the original.
- A verified placement and linkage plan for the actual hardware.
- An exact inventory of preserved, modified, newly allocated and excluded regions.
- A valid device-specific update artifact and verified updater compatibility.
- Required recovery materials and an independently usable recovery route.
- A controlled installation with readback or other justified verification, functional acceptance, and demonstrated restoration.

A hybrid may satisfy a small modification goal without recovering every original function. It does not establish a complete source rebuild or unrestricted ability to change unrelated functionality.

### 1.2 Route B: a full application rebuilt from source

Recover all application code and data dependencies necessary to boot and implement the intended feature set, including startup, interrupts, peripherals, runtime support, persistent storage, communication and measurement behavior.

Completion means the application is built from reviewed source and declared dependencies. A byte-preserved `.incbin` baseline is not source recovery. Any retained vendor binary component must be disclosed; an application using such a component must not be represented as wholly reconstructed source.

Whether the bootloader itself needs reconstruction depends on the deployment architecture. A complete application may legitimately retain a compatible vendor bootloader. Its interface, restrictions and recovery behavior still need evidence. A bootloader dump is helpful when obtainable without destructive changes, but is neither universally necessary nor sufficient for success.

### 1.3 What successful operation means

Successful upload, successful boot and successful operation are different milestones. The device must produce correct measurements and preserve calibration and persistent data, not merely enumerate over USB/Bluetooth or display a version string.

Define acceptance tolerances and workloads before testing. Measurement tolerances need a justified reference procedure; do not invent a universal percentage or infer calibration correctness from plausible readings.

## 2. Current implementation and evidence

### 2.1 Evidence available at the baseline

| Area | Implemented evidence | Important limit |
| --- | --- | --- |
| Containers | Extraction, payload integrity checks and format round-trip tooling across registered builds | Format correctness is not application equivalence |
| Original-byte builds | Assembler/linker preservation of vendor image bytes | No source-reconstruction credit |
| Compiled leaves | 5,072 bounded comparisons for eight candidates, including a partial accessor path | Not eight complete subsystems |
| Floating-point experiment | 10,947 bounded comparisons with recorded FPSCR behavior | Not whole calibration or measurement equivalence |
| Transfer-state integration | 1,424 direct/synthetic-caller cases | Synthetic caller and allocation |
| Session-helper integration | 4,352 direct/original-handler cases | Sequential emulator conditions |
| Cleanup reconstruction | 216 direct cases and 432 original-handler cases | Valid acyclic lists and no concurrent mutation |
| Combined replacements | 3,200 comparisons and 1,280 persistent calls | Selected command behavior only |
| Complete handshake handler | 3,200 comparisons and 1,280 persistent calls through compiled handler and callees | Not full packet reception or all command handlers |
| Original table dispatch | 5,120 bounded cases through both tables | Preselected tables; upstream frame validation excluded |
| Response finalizer | 576 direct cases and 1,680 dispatch-through-finalization cases | Stops before transport callbacks |
| Unit suite | 85 tests passed at baseline | Software regressions, not device certification |
| Manifests | All six checked against working-tree and LF checkout bytes | Integrity is not proof of physical compatibility |
| Incoming-edge audit | Conservative direct-branch and literal-pointer candidate inventory | Computed indirect targets remain unresolved |
| Deployment CLI | Repository archives, inspection, preflight and optional discovery | Device writing and complete readback are not implemented |

These suites overlap. Do not add the counts and call the result unique firmware coverage. Reports record cases, not the percentage of the application successfully recovered.

### 2.2 Current recovered command chain

The tested path includes original table lookup and indirect dispatch, the recovered handshake handler, recovered state/cleanup behavior, and recovered response finalization. The relevant guides are [HANDSHAKE.md](reconstruction/HANDSHAKE.md), [DISPATCH.md](reconstruction/DISPATCH.md) and [FINALIZE.md](reconstruction/FINALIZE.md).

The latest integrated test stops at `0x0802732a`. That is a documented post-finalizer boundary, not completion of the entire dispatcher or actual transport delivery. Upstream framing/CRC/mode selection and downstream callbacks remain outside the integrated evidence.

### 2.3 Known facts that must not be generalized

- The reference decoded image has SHA-256 `23c31b7dabc59fe35a698cbd4f690498ded9bbb9f6590f3f2ea72ae5cfd157f6`.
- The reference application vector table is located at `0x08010000` in the decoded image. The zero-padded lower region is not an acquired bootloader dump.
- Image extent establishes shipped bytes, not the physical flash capacity or availability of unoccupied space.
- The state helper reads the pointer at `0x080293fc`, whose reference value is `0x20000c0c`, then reads offset `0x0d`. The effective byte address is `0x20000c19`, not `0x20000c0d`.
- A prior test initialized the wrong address and falsely appeared to cover different state values. Preserve the regression and independent oracle that expose this failure mode.
- The handshake handler saves incoming `r3` and restores it into `r0` on return. Recovered code preserves this machine behavior; it is not evidence of a semantic status-code API.
- Finalization checks reported capacity after the handler writes its payload. It is not a preventive bounds check for those earlier writes.
- Emulator MMIO regions are generally mapped memory rather than accurate peripheral models. Even matching MMIO traces do not prove real hardware behavior.
- Read observers are restricted to MMIO because an existing Unicorn conditional-VFP regression exposed an instrumentation defect. Keep that regression intact.

## 3. Complete remaining-work register

Status meanings: **partial** means some relevant work exists but acceptance is unmet; **blocked** means required external evidence is missing; **not established** means no sufficient proof exists. None means impossible.

| ID | Work item | Current state | Required completion evidence |
| --- | --- | --- | --- |
| R01 | Exact MCU, board, silicon and capacities | Blocked on device evidence | Identifiers/photos/readouts with provenance and matching primary documentation |
| R02 | Authoritative memory map | Partial | Every relevant flash/RAM/persistent region classified with permissions and owners |
| R03 | Physical replacement location | Not established | Confirmed capacity, allocation, erase geometry and non-use by other firmware paths |
| R04 | Bootloader/update requirements | Partial | Verified acceptance checks, transitions, write ranges and failure behavior |
| R05 | Device-specific backups | Incomplete | Identified recovery-critical data, verified captures, protected-region alternatives |
| R06 | Recovery independent of replaced application | Not established | Reproduced recovery and restoration on the exact supported configuration |
| R07 | Real deployment transport | Not implemented | Reviewed protocol implementation and hardware transaction evidence |
| R08 | First intentional modification | Not selected | Narrow change specification, independent expected behavior and regression scope |
| R09 | Replacement-boundary/control-flow analysis | Partial | Reviewed direct/indirect entries, shared code and literal ownership |
| R10 | Device-valid linking | Emulator-only | Target linker layout, map file, bounds, ABI and resource validation |
| R11 | Modified update-package generation | Not established | Encode/decode checks and exact permitted write inventory for a real layout |
| R12 | Integration around reconstructed chain | Partial | Frame validation, selection policy, callbacks and transport behavior |
| R13 | Broader behavioral validation | Partial | Independent oracles, realistic traces, sequences, error paths and mutations |
| R14 | Interrupt/concurrency behavior | Not established | Shared-state, interrupt, DMA and timing analysis plus applicable tests |
| R15 | Fresh original-device baseline | Partial historical captures | Repeatable captures tied to exact device and installed image/version |
| R16 | Controlled installation trial | Not performed here | Verified candidate, installation journal and post-install checks |
| R17 | Hardware functional regression | Not established | Measured results for affected features and critical unaffected behavior |
| R18 | Restore verification | Not established | Original state restored, including persistent compatibility and calibration |
| R19 | Evidence-based deployment gate | Closed scaffolding exists | Reviewed policy binding artifact, identity, recovery and behavioral evidence |
| R20 | Complete code/data classification | Partial | Region inventory and resolved executable/data ambiguity |
| R21 | Complete application control-flow recovery | Partial | Function boundaries, callbacks, tables and indirect edges accounted for |
| R22 | Remaining application source | Mostly unreconstructed | Reviewed compilable implementations and their dependencies |
| R23 | Types, globals and persistent formats | Partial | Layout assertions, access semantics, ownership and versioned storage schemas |
| R24 | Startup and runtime | Not fully reconstructed | Vector/reset/data/BSS/clock/runtime/scheduler implementation |
| R25 | Peripherals and interrupt implementation | Not fully reconstructed | Target-specific drivers and hardware-observable validation |
| R26 | Whole-application build system | Not established | Complete reproducible source build with explicit retained binary dependencies |
| R27 | Whole-system equivalence | Not established | System-level original/rebuilt comparison under declared coverage and limits |

R01-R19 support a first real modification, with scope proportional to the affected behavior. R20-R27 are additional full-source-rebuild requirements. Some full-rebuild analysis is also necessary for a particular hybrid replacement when its dependencies cross those areas.

## 4. Repository rules and artifact organization

Read [agents.md](agents.md), [docs/VALIDATION.md](docs/VALIDATION.md), [ROADMAP.md](ROADMAP.md), and the deployment documentation before changing the workflow.

Preserve original vendor containers, decoded reference images and raw exports. Make improvements in reviewed reconstruction and analysis artifacts. Never silently alter the reference to make a comparison pass. Keep raw export, annotated export, compilable reconstruction, emulator fixture and proposed device artifact clearly distinguished.

| Material | Existing location or required destination |
| --- | --- |
| Target identity and artifact paths | `pipeline/devices.json`, `pipeline/config.py` |
| Vendor image and raw analysis | `firmware/<target>/` |
| Reviewed reconstructed C | `reconstruction/` |
| Human-readable annotations | `reconstruction/annotations/`, generated annotated output |
| Local compiler products | `build/`, ignored by Git |
| Regression checks | `tests/` |
| Reproducible validation reports | `reconstruction/*_validation.json`, target analysis reports |
| Historical device evidence | `docs/evidence/` |
| Deployment preparation and policy | `deployment/` |
| CI | `.github/workflows/validation.yml` |

Future artifact locations suggested below are proposals, not claims that corresponding tools exist. Preserve existing naming conventions where practical.

Record the commit, source hashes, input-image hash, tool versions, flags, linker script, random seed, execution bounds and environment for each experiment. All generated text should use explicit UTF-8 and LF. Serialize repository paths with forward slashes; do not embed Windows separators into portable manifests.

Write manifests last. Do not re-stamp old captures as fresh hardware evidence. Do not regenerate a pinned deployment catalog merely to recognize a modified candidate.

## 5. Reproduce the current offline baseline

### 5.1 Prepare a clean environment

Commands in this section exist at the baseline. Run them from the repository root. Review generated changes before committing. Use a separate checkout for regeneration if the current working tree contains uncommitted work.

```sh
git status --short
git rev-parse HEAD
python --version
python -m venv .venv
```

Activate the environment for the shell in use:

```sh
# POSIX shell
. .venv/bin/activate
```

```powershell
# PowerShell
.\.venv\Scripts\Activate.ps1
```

Then install the repository-pinned Python dependencies:

```sh
python -m pip install -r requirements.txt
python -m pip freeze
python pipeline/run.py --list
python -m deployment capabilities
python -m deployment targets
```

CI currently uses Python 3.12. The pinned analysis requirements are Capstone 5.0.9, Unicorn 2.1.4 and Z3 Solver 5.3.3.0 at this baseline. Check `requirements.txt` rather than assuming these remain current forever.

Install a GNU ARM Embedded compiler, objcopy, nm and objdump. On a compatible Ubuntu environment the current CI uses:

```sh
sudo apt-get update
sudo apt-get install -y gcc-arm-none-eabi binutils-arm-none-eabi --no-install-recommends
arm-none-eabi-gcc --version
```

For a separately installed compiler, set `ARM_GCC` to its executable. Examples contain placeholders that must be replaced:

```sh
export ARM_GCC=/absolute/path/to/arm-none-eabi-gcc
```

```powershell
$env:ARM_GCC = 'C:\path\to\bin\arm-none-eabi-gcc.exe'
```

The harness expects sibling tools. Compiler availability does not establish a valid device build. Preserve the actual version, flags and hashes in reports.

### 5.2 Run software and reconstruction checks

```sh
python -m unittest discover -s tests -v
python reconstruction/render_annotations.py
python reconstruction/render_navigation.py
python pipeline/build_reconstruction.py
python reconstruction/validate_calibration.py
python reconstruction/validate_hybrid.py
python reconstruction/validate_session_hybrid.py
python reconstruction/validate_cleanup.py
python reconstruction/validate_combined.py
python reconstruction/validate_finalize.py
python reconstruction/audit_patch_edges.py
```

`validate_finalize.py` also rebuilds and runs the handshake and dispatch prerequisites. They can be run separately during development:

```sh
python reconstruction/validate_handshake.py
python reconstruction/validate_dispatch.py
```

Avoid treating nested runs as independent evidence or adding their repeated counts. The edge audit is expected to return exit 2, INCONCLUSIVE. Inspect its JSON; do not mask every nonzero exit as acceptable.

### 5.3 Re-run analysis as needed

The default pipeline excludes live, network-download and Ghidra stages. It regenerates substantial analysis, so preserve the initial state and review diffs.

```sh
python pipeline/run.py --device rc-102/hw1-fw4.14
```

A targeted offline verification subset is:

```sh
python pipeline/run.py --all-devices --only 1,13,15,16
```

For confidence summaries and manifests after other generation:

```sh
python pipeline/run.py --all-devices --only 17,12
python pipeline/tools/check_manifest.py --all
python pipeline/release_gate.py
git diff --check
git status --short
```

An orchestration exit 2 means incomplete/inconclusive evidence. A release-gate exit 2 is the expected current blocked result, not a release pass. Exit 1 indicates failure. A report generator exiting 0 only means its own work completed; read report status and scope.

### 5.4 Re-run Ghidra deliberately

Set `GHIDRA_HOME` and `JAVA_HOME` to a compatible installed Ghidra/JDK combination. Existing exports were generated with the tool versions recorded in the repository; verify compatibility before regeneration.

```sh
python pipeline/run.py --device rc-102/hw1-fw4.14 --only 6,7,8,9,10,14,17,12
```

Stage 6 is a host analysis action, not a device capture. Review lost functions, newly decoded regions, warning changes, and `recovery_delta.json`. A lower function count can be either improved classification or lost recovery; inspect it.

Do not run stages 2 or 11 as part of a supposedly write-free inventory. They are explicit live operations, and the current stage descriptions disclose session behavior. The presence of a query-like name does not establish that a command is read-only.

## 6. Establish exact device identity and hardware

### 6.1 Required identity record

Record the model, serial, hardware revision, running firmware, bootloader version, connection identifiers, host OS, vendor-app version, timestamp and acquisition method. Distinguish a raw reply from a decoded field and an inference.

Obtain the exact MCU marking and board revision where possible. If documented non-destructive debug access is already available, read the applicable device-identification and flash-size information using the correct device reference material. Do not guess register semantics based only on a family resemblance.

A vendor serial field, USB descriptor, BLE address or service UUID is not an MCU part number. A service UUID alone does not prove whether a separate radio processor exists. Absence of references in the recovered application does not prove absence of external hardware.

### 6.2 Hardware evidence package

Required items, where available without destructive actions:

- Original identity responses and raw bytes, alongside decoding code/version.
- Device and board photographs, including readable package markings and revision silkscreen.
- Documented debug connection and read-only acquisition logs, if access exists.
- Exact part-specific reference documents and their revisions.
- Physical flash/RAM capacity and erase/bank geometry.
- Memory protection and boot selection information obtainable without changing configuration.
- Inventory of external nonvolatile memory, radio/controller components and sensor interfaces, with uncertain items labeled.

Do not claim photographs alone guarantee all hardware unknowns are resolved. Markings may be obscured, parts may have variants, and boot configuration may depend on device state.

### 6.3 Memory-map deliverable

For each range, record start/end, physical owner, purpose, read/write/execute properties, erase unit, source of evidence, mutability, backup method and protection policy. Include application code/data, vector tables, bootloader, configuration/calibration, logs, settings, external storage and reserved regions.

The map must account for both byte-level replacement and erase-page effects. A four-byte patch may require erasing a page containing unrelated data. A zero-filled or all-ones region in a vendor artifact is not sufficient evidence that the corresponding physical region is free.

**Gate:** no device-specific linking or package approval until required placement facts are established.

## 7. Acquire, preserve and qualify recovery materials

### 7.1 Preserve the repository baseline now

These are implemented offline commands:

```sh
python -m deployment backup --target rc-102/hw1-fw4.14 --source repository --output ../rc102-original.zip
python -m deployment verify-backup ../rc102-original.zip
```

Use a new output path. Preserve a verified second copy on independent storage. This archive contains pinned repository artifacts, not a complete readback of the device.

### 7.2 Identify recovery-critical state

Inventory application bytes, bootloader if readable, settings, calibration, option/configuration information, external storage, persistent schemas, supported data exports and any material needed to restore functionality. Do not assume a generic configuration text blob contains every unit-specific calibration value.

For each item, state whether it is acquired, protected/unreadable, unavailable through the current interface, recoverable through a documented alternate route, or not yet understood.

Acquire repeat readbacks where possible and compare hashes. For legitimately changing regions, identify the reason and record acquisition conditions rather than demanding impossible equality or silently discarding differences.

### 7.3 Recovery qualification

Document how recovery is entered when the application does not boot. Establish whether this depends on a protected bootloader, hardware pin, documented button sequence, debug access or manufacturer service. Do not infer generic STM32 DFU from a USB connector.

Verify compatibility of the intended original version and persistent data. An application downgrade can fail if a newer build changes stored formats. Restoration is not complete until measurements, calibration-dependent behavior and settings are verified.

Protected regions do not automatically require unlocking. Some protection changes erase data or irreversibly alter access. If a required region cannot be acquired non-destructively, stop that acquisition and determine an equivalent recovery policy. Do not mass erase or alter protection merely to obtain a dump.

**Gate:** a backup hash alone is insufficient; the restore route must be usable and demonstrated under the supported configuration.

## 8. Reverse-engineer bootloader and update requirements

Study original updater code, available bootloader bytes, documented device behavior and primary manufacturer material. Keep observation separate from inference.

Produce a protocol/state-machine specification covering:

1. Application-to-bootloader transition and whether the application is required to initiate it.
2. Identity and compatibility handshake in each mode.
3. Accepted container/header/block structure, address and size semantics, checksums and authentication if present.
4. Whether encryption/obfuscation is merely encoding or whether a cryptographic signature authorizes installation.
5. Sequence numbers, acknowledgements, retry rules, buffering and transport chunk sizes.
6. Erase boundaries, write alignment, permitted regions and whether the updater writes omitted regions.
7. Image verification, activation/commit conditions, vector validation and reboot behavior.
8. Version restrictions, downgrade policy and persistent-data migration behavior.
9. Timeout, disconnect, partial-write and host-restart behavior.
10. Recovery when activation or application startup fails.

Recomputing a CRC is not evidence that an authenticated update will be accepted. If custom image authorization is unavailable, determine whether an explicitly supported alternative exists. Do not represent missing signing capability as a packaging bug or assume recovery provides permission to bypass it.

No generic erase/write/bootloader-entry commands are supplied here because the applicable device protocol and recovery conditions are not yet established. Future executable instructions must name the exact supported device, bootloader and tool version and link the evidence that justifies each mutating operation.

## 9. Extract and map the original firmware

### 9.1 Source acquisition and container validation

Retain official package provenance, original bytes, acquisition date, source URL/package version, sizes and hashes. Re-acquisition must not silently overwrite the pinned baseline.

Verify header bounds, block counts, sizes, addresses, decompression behavior and integrity fields. Reject truncated, overlapping or out-of-range material according to the format contract. Confirm decode/encode behavior independently where possible.

Distinguish container bytes, block payloads, address-space padding and physically acquired bytes. Do not upload a flat padded `flash.bin` as a whole-chip image.

### 9.2 Memory and code discovery

Seed analysis from credible vectors, reset code, direct branches, reviewed function pointers and dispatch tables. Use the correct architecture, Thumb state, image base, RAM/MMIO mapping and floating-point support.

Maintain a region inventory with code, literal pool, table, string, padding and unknown classifications. Do not force-decode every unknown byte as a function. Likewise, printable instruction bytes are not automatically strings.

Compare independent decoders carefully. Formatting agreement is weaker than semantic agreement. Preserve condition codes, operand order, register widths, shifts, flag updates, PC-relative semantics and writeback.

### 9.3 Completion criteria

For a hybrid change, resolve every region and dependency relevant to the modified path and its interfaces. For a full rebuild, account for every application region needed for supported operation. Record unresolved or apparently unreachable regions rather than declaring them irrelevant without evidence.

## 10. Recover functions, types, globals and control flow

### 10.1 Function contract worksheet

For every reconstructed function, record:

- Target/image hash, entry, extent and any alternate or interior entry points.
- Original bytes and credible instruction decoding.
- Calling convention, arguments, return behavior, stack alignment and saved registers.
- Global and indirect memory accesses, access widths, ordering and volatile semantics.
- Calls, tail calls, tables, callbacks and external dependencies.
- Preconditions such as buffer capacity, alignment, list shape and valid pointer ranges.
- Error, timeout, fault and non-returning behavior.
- Floating-point mode, rounding, exceptional values and status effects when applicable.
- Shared-state assumptions and interrupt/concurrency dependencies.
- Independent oracle, test domain, mutations, observed instruction coverage and remaining uncertainty.

### 10.2 Structural recovery

Recover structures from multiple accesses and callers rather than naming every pointer from a single decompiler guess. Add compile-time size/offset assertions. Represent unknown gaps explicitly. Preserve signedness and load/store width; a word load replacing a byte load has already caused a real defect in this project.

Trace linked lists, queues, object ownership, callbacks and allocator contracts. Identify which fields are asynchronous, persistent, command-specific or reused across modes.

### 10.3 Indirect control flow

Inventory vectors, function-pointer tables, virtual tables, computed branches, callbacks and dynamic registration. Record table bounds and sentinel behavior. Determine which entries are actually executable pointers and which are data.

The current halfword scan intentionally includes overlapping decodes and data-derived candidates. Classify candidates with evidence, but do not turn an empty scan result into a whole-program proof. A computed pointer may never occur as a literal word in the image.

### 10.4 Raw source, reviewed names and compilable source

Keep the raw Ghidra output as an analysis artifact. Preserve meaningful annotations through the existing rendering workflow. Build reviewed C separately with address and contract references so the distinction remains visible.

Do not fix warnings by inserting dummy returns, zero-valued globals, skipped calls or empty peripheral functions and then claim functional recovery. Any deliberate stub must be explicit and the resulting test labeled partial.

## 11. Reconstruct source and build contracts

### 11.1 Implementation requirements

Use fixed-width assumptions justified for the target, explicit unsigned arithmetic when the original wraps, and deliberate sign extension/truncation. Avoid undefined C behavior for operations that are defined in the machine code. Review aliasing, alignment, shift widths and integer promotions.

Use volatile only where justified by actual access semantics; volatile is not a concurrency primitive. Preserve necessary barriers, atomicity and access ordering in peripheral or shared-state code.

Document whether the function is exact reconstruction, a bounded path, an adapter, or an intentional functional change. A local guard for unsupported inputs is not recovered behavior for those inputs.

### 11.2 Toolchain and build identity

Record architecture, CPU, Thumb mode, floating-point ABI, compiler version, optimization, link-time optimization, runtime libraries, section placement and all linker options. Check compiler-generated helper calls and runtime dependencies.

Do not assume identical C produces the same binary under a new compiler. Revalidate affected artifacts after changes in compiler, flags, linker layout, source, imported helpers or test instrumentation.

### 11.3 Full build properties

For a complete source build, supply the startup code, vector table, reset entry, `.data` loading, `.bss` clearing, constructors if applicable, heap/stack boundaries, interrupt handlers, runtime support and peripheral initialization. Generate map files and assess worst-case stack/resource use.

Explain all retained binary components. Pin licenses and attribution for vendor-derived or third-party material. Repository availability does not by itself establish redistribution rights.

## 12. Design independent behavioral validation

### 12.1 Required layers

1. **Artifact integrity:** reference hashes, exact input identity and declared address mappings.
2. **Format checks:** original container validity and correct candidate encode/decode behavior.
3. **Machine execution:** original ARM versus compiled ARM, not only Python versus Python.
4. **Independent expected behavior:** mathematical or byte-level oracles derived separately from the candidate implementation.
5. **Integration:** original callers, tables, state transitions and compiled callees exercised together.
6. **System/hardware:** interrupts, peripherals, timing, persistence and actual device observations.

Passing one layer does not imply the next.

### 12.2 Case design

Use boundary values, all relevant enum values, signed/unsigned extremes, zero and nonzero states, valid/invalid signatures, empty/full/wraparound queues, list head/middle/tail/absent cases, and repeated operation sequences. Vary pointer placement and alignment within the supported contract where meaningful.

For floating-point code include NaNs, infinities, signed zero, subnormal behavior, overflow/underflow, rounding and FPSCR effects. State which behaviors are compared and which target-specific modes are assumed.

Test malformed inputs according to the contract. Do not claim resilience to arbitrary invalid pointers because a valid-pointer suite passes.

### 12.3 Observations and acceptance

Compare relevant returns, preserved registers, stack restoration, final non-stack memory, ordered writes where order is observable, MMIO events, expected call paths and completion state. Final memory equality alone can hide changed write ordering. Stack scratch differences may be legitimate, but stack balance, bounds and live data are not optional.

Function tests require actual return. Bounded subsystem tests require the declared boundary. Fault, timeout, budget exhaustion and unsupported execution must remain distinguishable. No fake return is allowed to convert an incomplete execution into success.

### 12.4 Mutation controls

Introduce deliberately wrong outputs, wrong load widths, wrong state addresses, omitted writes, incorrect comparisons, skipped callees, incorrect branch targets and corrupted package fields. Verify the tests reject them for the intended reason.

A negative case that always differs for an unrelated reason does not validate the intended distinction. Preserve the state-address regression: the old suite left the actual state at zero and passed a vacuous comparison.

### 12.5 Formal analysis

Use symbolic reasoning for tractable leaf contracts, arithmetic, bounds, state transitions and bit-level formatting. If proving original-versus-compiled equivalence, specify the instruction semantics and memory/ABI assumptions on both sides. Auxiliary proofs over a hand-written model are not proofs of the firmware.

Solver timeout or unknown remains unresolved. Explicit assumptions must not exclude the very behavior the test is intended to validate.

## 13. Extend subsystem and whole-system coverage

The immediate software sequence is:

1. Validate upstream frame parsing, integrity checks and mode/table selection.
2. Resolve optional owner callbacks and response-delivery callbacks.
3. Trace actual USB/Bluetooth receive and transmit state machines.
4. Exercise complete command transactions with realistic buffering and sequence behavior.
5. Recover additional handlers and shared services by dependency order.
6. Expand into measurement acquisition, spectrum accumulation, calibration, display/UI, alarms, storage and power management.
7. Integrate startup, interrupt and scheduler behavior into a coherent system build.

For each subsystem, identify states, inputs, outputs, persistence, timers, failure paths and concurrent actors. Define a reproducible trace/replay format where useful. Real captures should include raw transport data and exact firmware/device identity, not only decoded summaries.

Do not generate the reference outputs using the same implementation under test. Record uncertainty where original behavior depends on unavailable sensor or peripheral state.

## 14. Integrate compiled replacements safely

### 14.1 Patch contract

Before replacing a function, establish the original identity, overwritten instruction boundaries, all relevant incoming paths, literal-pool ownership, branch ranges, Thumb entry-bit semantics and placement requirements.

Preserve interior bodies unless their removal is justified. An entry trampoline does not automatically redirect callers that jump into the body. A shared tail or literal pool can belong to multiple routines.

### 14.2 Physical allocation

Confirm that destination bytes exist physically and are not used by the application, bootloader, persistent data, second-bank operation or future update behavior. Verify execution permissions and page ownership. An emulator mapping up to a chosen address is not evidence of physical capacity.

Current addresses in the `0x08070000` region are synthetic allocations. Do not adapt a device uploader to accept them simply because the tests use them.

### 14.3 Link and audit

Use explicit linker sections and size/overlap assertions. Check actual symbols, disassembly, literal pools, relocation reachability and compiler helper calls. Enumerate every changed range, including padding between original end and appended code.

For every changed range, record original/candidate bytes or hashes, intended purpose, physical owner, affected erase pages and how unrelated bytes are preserved. Verify unchanged regions against the original artifact.

Test the linked image through original callers, then through larger integration boundaries. Test simultaneous replacements, not only each function in isolation. Preserve state across repeated commands and verify post-operation invariants.

## 15. Construct and verify a device update package

This is required future work. Existing container tooling and emulator fixtures are not a verified custom-update pipeline.

### 15.1 Candidate build input

Bind a candidate to one target and one reviewed layout. Its manifest should include source commit/hashes, original image/container hashes, exact toolchain, linker layout, intended change, affected functions/regions, preserved regions, tests, unresolved assumptions and artifact hashes.

Reject an unspecified target, unsupported layout, unproven allocation, malformed input, changed protected region or ambiguous write set. A user-supplied `approved: true` field must not create approval.

### 15.2 Packaging validation

Build the device's actual accepted container format. Recompute only the fields whose meaning is established. Handle compression, checksums and authentication according to the verified updater/bootloader contract.

Decode the candidate package independently and compare the reconstructed application bytes with the intended linked image. Verify block address ranges, alignment, overlap, integer overflow, total lengths and erase effects. Ensure padding cannot turn an application update into a bootloader overwrite.

Cross-check preserved calibration/settings regions. Record compatibility of persistent schemas. If the intended deployment route cannot install the artifact, stop rather than substituting a different transport or raw-memory write.

### 15.3 Reproducibility and review output

Build twice in controlled clean environments where feasible. Explain any nondeterministic fields. Produce the exact candidate, map file, disassembly, changed-byte inventory, package verification report and device-specific preflight record.

Do not label a package deployable until the relevant gate is satisfied. Keep emulator fixtures unmistakably separate from device candidates; directory names and flags must reinforce, not replace, technical enforcement.

## 16. Implement the device transaction and recovery workflow

### 16.1 Current CLI boundary

Implemented inspection and preflight examples:

```sh
python -m deployment inspect --target rc-102/hw1-fw4.14 --image firmware/rc-102/hw1-fw4.14/rc-102z.bin
python -m deployment plan --target rc-102/hw1-fw4.14 --image firmware/rc-102/hw1-fw4.14/rc-102z.bin --backup ../rc102-original.zip --transport usb --endpoint YOUR_DEVICE_IDENTIFIER
python -m deployment recovery
```

The endpoint in this plan is an unverified user claim. `plan` is offline and blocked. `deploy` and `restore` currently perform checks and refuse without sending update commands. `backup --source device` is unavailable. Do not interpret recognition of vendor bytes as authorization for a particular physical unit.

Optional discovery, when explicitly intended on the device host:

```sh
python -m deployment discover --transport bluetooth --live
python -m deployment discover --transport usb --live
```

Discovery requires its optional dependencies and host permissions. It enumerates advertisements/descriptors; it does not establish a verified firmware session or select a target automatically.

### 16.2 Future writer requirements

Implement a reviewed transaction state machine with exclusive device ownership, exact identity verification, artifact/backup binding, power prerequisites justified for that device, append-only journaling and validated protocol acknowledgements.

Required phases:

1. Resolve and verify the exact physical device and mode.
2. Verify recovery prerequisites and required backup material.
3. Inspect candidate layout, authentication, version transition and persistent compatibility.
4. Present the concrete device/artifact/write-region plan according to the deployment policy.
5. Recheck identity and bytes immediately before mutation.
6. Journal the planned operation before erase/write/commit actions.
7. Perform only permitted writes, honoring verified alignment, boundaries and sequencing.
8. Verify installed content through supported readback or a justified device verification mechanism.
9. Activate using the proven device procedure.
10. Reconnect to the same device, verify running identity and execute acceptance tests.
11. Recover according to the tested route if verification fails.

Do not blindly retry ambiguous erase/write/commit operations. Determine whether the device completed the operation before deciding what comes next. Never silently switch transport, endpoint, device or image. A host-side journal cannot manufacture device-side atomicity or power-loss safety.

## 17. Run the controlled hardware program

### 17.1 Baseline before modification

Capture identity, firmware/bootloader, supported settings, calibration-related information, communications, display/buttons, measurement/spectrum behavior, alarms, logging and power states relevant to the change. Preserve raw results and environmental/reference conditions.

Use a recoverable development unit for experiments. Do not use unvalidated modified measurement behavior as the basis of a radiation-safety decision.

### 17.2 First intentional change

Choose a change with a clear observable effect and limited dependencies. Prefer a diagnostic or presentation behavior whose impact can be isolated, if analysis identifies an appropriate candidate. Do not assume an arbitrary string or version-field edit is harmless; lengths, checksums and dependent behavior still matter.

Specify original behavior, modified behavior, unaffected behavior, test inputs, expected outputs and rollback expectations. First establish the no-change replacement under the accepted validation plan; then test the intentional difference explicitly.

### 17.3 Hardware acceptance matrix

| Area | Required observations |
| --- | --- |
| Boot | Cold/warm start, reset reason, initialization and sustained operation |
| Identity | Same device, expected build, expected bootloader and settings |
| Communication | Applicable USB/BLE operations, reconnects, framing, sequencing, timeouts |
| Measurement | Reference procedure, repeatability, expected units and calibration behavior |
| Spectrum | Acquisition, accumulation, channel interpretation, export and persistence |
| UI | Display, buttons, menus, indicators and error reporting |
| Alarms | Relevant thresholds, annunciation, acknowledgement and persistence |
| Storage | Settings/log retention, restart behavior, version compatibility |
| Power | Applicable charging, sleep/wake, battery and power-transition behavior |
| Timing/concurrency | Relevant interrupts, DMA, queues, watchdog and sustained loads |
| Intended change | Exact specified result without unexplained differences |
| Restore | Original application and persistent state restored and rechecked |

Tailor the matrix to actual hardware capabilities. Mark inapplicable items with justification; do not mark untested items passed.

### 17.4 Failure injection

Only after establishing a recovery-capable test setup, evaluate disconnect, host termination, stale responses, corrupt blocks, storage exhaustion, identity mismatch and interruption at relevant transaction phases. Power-loss tests require a deliberately recoverable development setup and a reviewed procedure, not casual testing on the only working unit.

Retain stage-specific logs, image hashes and recovery results. Mocked failures validate host software but do not establish real device recoverability.

## 18. Complete the full-source application rebuild

Route B additionally requires a subsystem-by-subsystem source inventory and a complete dependency graph. Count remaining functions only as a planning aid; a small interrupt or startup routine can matter more than hundreds of easy leaves.

Account for:

- Reset, vector table, exception handlers and runtime initialization.
- Clock tree, timers, watchdog and power transitions.
- Sensor/acquisition paths and DMA/interrupt interactions.
- Measurement mathematics, accumulation, calibration and formatting.
- USB/Bluetooth/radio interfaces and any separate controller protocol.
- Command parsing, authorization/state prerequisites and all required handlers.
- Display, buttons, alarms and user settings.
- Persistent storage, wear/erase management, logs and schema migration.
- Scheduler/event loop, queues, allocation and object lifetimes.
- Error handling, recovery states and diagnostic behavior.
- Compiler runtime and third-party libraries.

For each subsystem, close source, build, interface, testing and hardware obligations before calling it complete. Integrate progressively; verify cross-subsystem interactions and long-running operation rather than relying only on isolated function contracts.

A full rebuild need not be byte-identical to the vendor compiler output. It does need justified behavioral compatibility under declared conditions, a correct physical layout and a demonstrated deployment/recovery workflow. Differences must be understood and accepted, not merely hidden by a passing test count.

## 19. Evidence gates, CI and release records

### 19.1 Gate sequence

| Gate | Acceptance | What it does not authorize |
| --- | --- | --- |
| G0 Reference | Original artifact identity/provenance and decoding verified | Device compatibility |
| G1 Recovered function | Compilable contract plus original/compiled tests and mutations | Whole subsystem equivalence |
| G2 Integrated chain | Original callers and persistent sequences validated | Hardware timing or full dispatch |
| G3 Device layout | Exact hardware, memory map and permitted placement verified | Update/recovery safety by itself |
| G4 Package | Exact accepted-format candidate and changed-region checks | Physical installation without recovery |
| G5 Recovery/transaction | Verified recovery and supported writer policy | Functional correctness of the candidate |
| G6 Hardware trial | Intended behavior and applicable regressions pass | Untested configurations or full-source status |
| G7 Release decision | Complete scoped evidence reviewed and bound to artifacts/device | Universal no-brick guarantee |
| G8 Full-source completion | All application dependencies reconstructed and system-validated | Unsupported models or future changes |

The current repository release gate is intentionally conservative and remains closed. If a narrower hybrid-release policy is ever introduced, it must be a separately reviewed policy with explicit scope. Do not weaken the existing gate by changing booleans, suppressing blockers or treating missing tests as passed.

### 19.2 Release record

A future approved record must identify:

- Target and physical identity policy.
- Exact original and candidate artifact hashes.
- Source commit, compiler, flags, linker layout and packaging tool versions.
- Intended change and excluded behavior.
- Coverage matrix, original/rebuilt comparisons, mutations and hardware results.
- Backup hashes, inaccessible material and justified recovery alternatives.
- Verified recovery procedure and persistent-data compatibility.
- Transaction implementation/version and permitted transports.
- Known risks, unresolved items and the rationale for any accepted limitation.
- Installation and restoration logs for the supported configuration.

A stale record cannot approve a newly built image. Rebuilds, hardware revisions, bootloader changes and altered test dependencies require impact review and appropriate revalidation.

## 20. Execution order and ownership

### 20.1 Work that can continue in the repository

1. Extend the current chain through frame validation and transport callbacks.
2. Resolve the dispatcher and related callback contracts, including the preserved incoming-r3 behavior.
3. Classify incoming-edge candidates and resolve relevant indirect paths.
4. Recover additional command and measurement subsystems with independent contracts.
5. Improve shared build/test utilities without losing independent oracles or scope labels.
6. Design target-bound linking and package validation that refuses unknown physical layouts.
7. Strengthen negative tests, provenance, fault reporting and CI artifact retention.
8. Build the whole-source architecture incrementally as its dependencies are recovered.

### 20.2 Work requiring device/local access

1. Exact model/board/MCU/capacity evidence.
2. Device-specific state preservation and readback feasibility.
3. Bootloader/update acceptance and recovery evidence.
4. Actual transport/session validation.
5. Original baseline captures under reproducible conditions.
6. Controlled installation, functional comparison and restoration.

These streams can proceed independently until their integration gates meet. Do not stop all source work because a photograph is missing, and do not start physical writes because software progress is substantial.

### 20.3 Next milestone definition

A useful next milestone is a complete bounded command transaction from validated frame input through response delivery, with actual original callbacks understood. Define callback/peripheral boundaries honestly where a host emulator cannot reproduce them. In parallel, establish hardware and recovery facts so emulator-only placement can eventually be replaced with a device-valid layout.

## 21. Instructions for an AI connected to the device

The following is a collection task, not authorization to flash, erase, unlock or change protection. Adjust only to explicit owner instructions and known device capabilities.

> Work from the latest `darkmatter2222/radiacode-firmware` checkout. Read `agents.md`, this document, `docs/HARDWARE.md`, `deployment/README.md`, `deployment/SAFETY.md` and `deployment/RECOVERY.md`. Record the commit and working-tree state before collecting evidence.
>
> Goal: establish exact hardware identity, memory layout, recoverability and baseline behavior needed for a future reviewed modified-firmware trial. Do not install firmware or run undocumented command sweeps as part of this collection.
>
> First inspect existing captures and artifacts. Distinguish repository firmware, actual device readback, vendor-app information and inference. Do not claim a complete backup from the repository archive or padded flash image.
>
> Inventory the host tools and intended physical device. Record model, serial, hardware revision, firmware and bootloader using supported methods. Preserve original raw replies and logs. Before sending any command, inspect its implementation and classify side effects. Session setup can write state; do not call it write-free without evidence. Do not use `0x0013` as a read-only query.
>
> Determine whether exact MCU, silicon revision, flash size, RAM capacity, bank/page geometry, board revision and external storage can be established through available non-destructive means. Use readable markings and part-specific primary documents where appropriate. Do not interpret vendor serial fields as MCU identification registers. If photographs or a physical action are needed, state exactly what is missing.
>
> Inventory application, bootloader, calibration, settings and configuration material needed for recovery. Acquire only through documented or reviewed non-destructive interfaces. Do not mass erase, change option bytes/readout protection, unlock protected flash or write another unit's calibration to obtain evidence. Record protected/unreadable regions and possible documented alternatives.
>
> Identify the supported official update/recovery route for this exact model and bootloader. Investigate whether recovery works without a functioning application and whether the desired original version can be restored. Do not invent button sequences or assume generic DFU. Clearly separate documentation, code analysis and actually reproduced observations.
>
> Capture a reproducible original-device baseline for communications and relevant settings/measurement behavior using the supported workflow. Record any authorized state changes precisely. Do not silently perform session writes, resets, time changes or bootloader transitions merely to make a capture succeed.
>
> Return a bundle with REPORT.md, an identity record, command log with raw requests/replies, files/readbacks with ranges and acquisition methods, relevant photos or references, a missing-evidence list and a manifest of sizes/SHA-256 values. Generate the manifest last and exclude its own hash. Keep original captures unchanged; place interpretations in separate files. Preserve sensitive device-specific material appropriately before publishing anything publicly.
>
> End with a table of established facts, inference, unresolved questions, blocked operations and the next concrete action needed for each blocker. Do not state flash-ready, recoverable or fully backed up unless the corresponding evidence exists.

## 22. Failure handling and stop conditions

| Observation | Required response |
| --- | --- |
| Reference hash mismatch | Identify the new target/artifact; do not reuse old applicability claims |
| Compiler unavailable | Report unavailable; do not reuse an old PASS as a new build result |
| Original and compiled disagree | Minimize the case, inspect original bytes and candidate semantics, preserve a regression |
| Independent oracle disagrees with both | Reassess setup and oracle; two matching implementations can share a mistaken assumption |
| Instrumentation changes behavior | Isolate observer effects and preserve a regression before trusting new measurements |
| Budget exhausted or unmapped access | Fail or mark explicitly incomplete; do not synthesize completion |
| Unknown incoming edge/shared region | Keep the boundary unresolved and avoid physical replacement approval |
| Unknown allocation or erase geometry | Block package/deployment approval |
| Missing recovery-critical data | Identify a verified alternate recovery route or stop the physical trial |
| Authentication rejects custom images | Determine supported capabilities; do not assume CRC changes solve it |
| Ambiguous update completion | Preserve logs and follow proven device-state recovery, without blind retry |
| Device identity changes after reconnect | Re-resolve the same physical device; never continue by name alone |
| Manifest mismatch | Investigate generation order/encoding/source changes; do not simply update hashes to conceal unexpected modifications |
| Green CI but no hardware evidence | Keep physical deployment blocked |
| Successful boot but changed measurement behavior | Treat as failed functional acceptance and follow the verified restore plan |

## 23. Final acceptance checklist

### First source modification and successful re-upload

- [ ] Exact physical target and running baseline are established.
- [ ] Intended modification and unaffected-behavior requirements are written.
- [ ] Original artifacts and required device-specific recovery material are preserved and verified.
- [ ] Application-independent recovery and persistent compatibility are demonstrated.
- [ ] Relevant original code, data, indirect edges and replacement boundaries are reviewed.
- [ ] Compiled candidate passes independent and original-binary comparisons under stated contracts.
- [ ] Simultaneous replacements and realistic state sequences are tested.
- [ ] Physical linker layout, erase effects and protected regions are verified.
- [ ] Actual update package decodes to exactly the intended image and satisfies bootloader requirements.
- [ ] Writer/session behavior is implemented, reviewed and hardware-validated.
- [ ] Candidate, backup, target and evidence hashes are bound to the installation plan.
- [ ] Installation and post-install verification succeed on the identified device.
- [ ] Intended behavior and critical unaffected functions pass the hardware matrix.
- [ ] Restore to the original state is demonstrated and documented.
- [ ] Remaining limitations are explicit; no universal no-brick or whole-firmware claim is made.

### Full source rebuild

- [ ] All required application code/data regions are accounted for.
- [ ] Function boundaries and relevant direct/indirect control flow are resolved.
- [ ] Structures, globals, persistent formats and access semantics are reconstructed.
- [ ] Startup, vectors, runtime, scheduler, interrupts and peripherals are implemented.
- [ ] Remaining application and measurement subsystems build from reviewed source.
- [ ] Retained binary components, if any, are disclosed and the completion claim scoped accordingly.
- [ ] Complete linker/resource/ABI requirements are verified.
- [ ] Reproducible whole-application builds and subsystem integration pass.
- [ ] Original/rebuilt hardware comparisons and sustained operation pass defined criteria.
- [ ] The deployment, persistence, recovery and restoration obligations above also pass.

Unchecked items remain work. Do not replace this checklist with a percentage inferred from test counts or decompiler output size.

## 24. Repository references and terminology

### Primary repository references

- [Working rules](agents.md)
- [Roadmap](ROADMAP.md)
- [Validation contracts](docs/VALIDATION.md)
- [Hardware evidence and unknowns](docs/HARDWARE.md)
- [Hardware experiment stages](docs/TESTPLAN.md)
- [Initial integration assessment](reconstruction/INTEGRATION.md)
- [Cleanup reconstruction](reconstruction/CLEANUP.md)
- [Combined replacements](reconstruction/COMBINED.md)
- [Handshake handler](reconstruction/HANDSHAKE.md)
- [Original dispatch integration](reconstruction/DISPATCH.md)
- [Response finalization](reconstruction/FINALIZE.md)
- [Floating-point experiment](reconstruction/CALIBRATION.md)
- [Deployment preparation CLI](deployment/README.md)
- [Write-enablement requirements](deployment/SAFETY.md)
- [Recovery limitations and manufacturer references](deployment/RECOVERY.md)

Manufacturer and chip-document references are starting points, not newly verified instructions in this document. Consult current primary documentation for the exact model/part before using any physical update or debug procedure. Follow applicable restrictions and preserve device-specific evidence.

### Terms

| Term | Meaning here |
| --- | --- |
| Decompilation | A tool's source-like interpretation of machine code; not necessarily compilable or correct |
| Reconstruction | Reviewed source built from binary behavior, types, interfaces and supporting evidence |
| Differential test | Comparison of executions under controlled initial conditions |
| Independent oracle | Expected behavior derived separately from the candidate implementation |
| Hybrid image | Original bytes combined with compiled replacements |
| Emulator fixture | Test image whose address map need not match physical deployable storage |
| Device candidate | A target-bound artifact prepared for a real update route, still requiring approval/evidence |
| Boundary reached | Execution reached a specified internal stop point; not whole-function/system completion |
| Repository archive | Preserved known files, not automatically a device backup |
| Recovery | Re-establishing functional device state through a demonstrated route |
| Release ready | A scoped evidence-based decision for exact artifacts and supported hardware, not a universal guarantee |
