// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: world_data.proto

#ifndef PROTOBUF_INCLUDED_world_5fdata_2eproto
#define PROTOBUF_INCLUDED_world_5fdata_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_world_5fdata_2eproto 

namespace protobuf_world_5fdata_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[5];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_world_5fdata_2eproto
namespace protocol {
class Coord;
class CoordDefaultTypeInternal;
extern CoordDefaultTypeInternal _Coord_default_instance_;
class Position;
class PositionDefaultTypeInternal;
extern PositionDefaultTypeInternal _Position_default_instance_;
class RobotData;
class RobotDataDefaultTypeInternal;
extern RobotDataDefaultTypeInternal _RobotData_default_instance_;
class WheelsVelocity;
class WheelsVelocityDefaultTypeInternal;
extern WheelsVelocityDefaultTypeInternal _WheelsVelocity_default_instance_;
class WorldData;
class WorldDataDefaultTypeInternal;
extern WorldDataDefaultTypeInternal _WorldData_default_instance_;
}  // namespace protocol
namespace google {
namespace protobuf {
template<> ::protocol::Coord* Arena::CreateMaybeMessage<::protocol::Coord>(Arena*);
template<> ::protocol::Position* Arena::CreateMaybeMessage<::protocol::Position>(Arena*);
template<> ::protocol::RobotData* Arena::CreateMaybeMessage<::protocol::RobotData>(Arena*);
template<> ::protocol::WheelsVelocity* Arena::CreateMaybeMessage<::protocol::WheelsVelocity>(Arena*);
template<> ::protocol::WorldData* Arena::CreateMaybeMessage<::protocol::WorldData>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace protocol {

// ===================================================================

class Coord : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protocol.Coord) */ {
 public:
  Coord();
  virtual ~Coord();

  Coord(const Coord& from);

  inline Coord& operator=(const Coord& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Coord(Coord&& from) noexcept
    : Coord() {
    *this = ::std::move(from);
  }

  inline Coord& operator=(Coord&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Coord& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Coord* internal_default_instance() {
    return reinterpret_cast<const Coord*>(
               &_Coord_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Coord* other);
  friend void swap(Coord& a, Coord& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Coord* New() const final {
    return CreateMaybeMessage<Coord>(NULL);
  }

  Coord* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Coord>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Coord& from);
  void MergeFrom(const Coord& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Coord* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // double x = 1;
  void clear_x();
  static const int kXFieldNumber = 1;
  double x() const;
  void set_x(double value);

  // double y = 2;
  void clear_y();
  static const int kYFieldNumber = 2;
  double y() const;
  void set_y(double value);

  // @@protoc_insertion_point(class_scope:protocol.Coord)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  double x_;
  double y_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_world_5fdata_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Position : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protocol.Position) */ {
 public:
  Position();
  virtual ~Position();

  Position(const Position& from);

  inline Position& operator=(const Position& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Position(Position&& from) noexcept
    : Position() {
    *this = ::std::move(from);
  }

  inline Position& operator=(Position&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Position& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Position* internal_default_instance() {
    return reinterpret_cast<const Position*>(
               &_Position_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(Position* other);
  friend void swap(Position& a, Position& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Position* New() const final {
    return CreateMaybeMessage<Position>(NULL);
  }

  Position* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Position>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Position& from);
  void MergeFrom(const Position& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Position* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .protocol.Coord coord = 1;
  bool has_coord() const;
  void clear_coord();
  static const int kCoordFieldNumber = 1;
  private:
  const ::protocol::Coord& _internal_coord() const;
  public:
  const ::protocol::Coord& coord() const;
  ::protocol::Coord* release_coord();
  ::protocol::Coord* mutable_coord();
  void set_allocated_coord(::protocol::Coord* coord);

  // double theta = 2;
  void clear_theta();
  static const int kThetaFieldNumber = 2;
  double theta() const;
  void set_theta(double value);

  // @@protoc_insertion_point(class_scope:protocol.Position)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::protocol::Coord* coord_;
  double theta_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_world_5fdata_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class WheelsVelocity : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protocol.WheelsVelocity) */ {
 public:
  WheelsVelocity();
  virtual ~WheelsVelocity();

  WheelsVelocity(const WheelsVelocity& from);

  inline WheelsVelocity& operator=(const WheelsVelocity& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  WheelsVelocity(WheelsVelocity&& from) noexcept
    : WheelsVelocity() {
    *this = ::std::move(from);
  }

  inline WheelsVelocity& operator=(WheelsVelocity&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const WheelsVelocity& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const WheelsVelocity* internal_default_instance() {
    return reinterpret_cast<const WheelsVelocity*>(
               &_WheelsVelocity_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(WheelsVelocity* other);
  friend void swap(WheelsVelocity& a, WheelsVelocity& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline WheelsVelocity* New() const final {
    return CreateMaybeMessage<WheelsVelocity>(NULL);
  }

  WheelsVelocity* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<WheelsVelocity>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const WheelsVelocity& from);
  void MergeFrom(const WheelsVelocity& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(WheelsVelocity* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // double leftWheelVelocity = 1;
  void clear_leftwheelvelocity();
  static const int kLeftWheelVelocityFieldNumber = 1;
  double leftwheelvelocity() const;
  void set_leftwheelvelocity(double value);

  // double rightWheelVelocity = 2;
  void clear_rightwheelvelocity();
  static const int kRightWheelVelocityFieldNumber = 2;
  double rightwheelvelocity() const;
  void set_rightwheelvelocity(double value);

  // @@protoc_insertion_point(class_scope:protocol.WheelsVelocity)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  double leftwheelvelocity_;
  double rightwheelvelocity_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_world_5fdata_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class RobotData : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protocol.RobotData) */ {
 public:
  RobotData();
  virtual ~RobotData();

  RobotData(const RobotData& from);

  inline RobotData& operator=(const RobotData& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  RobotData(RobotData&& from) noexcept
    : RobotData() {
    *this = ::std::move(from);
  }

  inline RobotData& operator=(RobotData&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const RobotData& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RobotData* internal_default_instance() {
    return reinterpret_cast<const RobotData*>(
               &_RobotData_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  void Swap(RobotData* other);
  friend void swap(RobotData& a, RobotData& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline RobotData* New() const final {
    return CreateMaybeMessage<RobotData>(NULL);
  }

  RobotData* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<RobotData>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const RobotData& from);
  void MergeFrom(const RobotData& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RobotData* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .protocol.Position position = 1;
  bool has_position() const;
  void clear_position();
  static const int kPositionFieldNumber = 1;
  private:
  const ::protocol::Position& _internal_position() const;
  public:
  const ::protocol::Position& position() const;
  ::protocol::Position* release_position();
  ::protocol::Position* mutable_position();
  void set_allocated_position(::protocol::Position* position);

  // .protocol.WheelsVelocity wheelsVelocity = 2;
  bool has_wheelsvelocity() const;
  void clear_wheelsvelocity();
  static const int kWheelsVelocityFieldNumber = 2;
  private:
  const ::protocol::WheelsVelocity& _internal_wheelsvelocity() const;
  public:
  const ::protocol::WheelsVelocity& wheelsvelocity() const;
  ::protocol::WheelsVelocity* release_wheelsvelocity();
  ::protocol::WheelsVelocity* mutable_wheelsvelocity();
  void set_allocated_wheelsvelocity(::protocol::WheelsVelocity* wheelsvelocity);

  // @@protoc_insertion_point(class_scope:protocol.RobotData)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::protocol::Position* position_;
  ::protocol::WheelsVelocity* wheelsvelocity_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_world_5fdata_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class WorldData : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protocol.WorldData) */ {
 public:
  WorldData();
  virtual ~WorldData();

  WorldData(const WorldData& from);

  inline WorldData& operator=(const WorldData& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  WorldData(WorldData&& from) noexcept
    : WorldData() {
    *this = ::std::move(from);
  }

  inline WorldData& operator=(WorldData&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const WorldData& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const WorldData* internal_default_instance() {
    return reinterpret_cast<const WorldData*>(
               &_WorldData_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    4;

  void Swap(WorldData* other);
  friend void swap(WorldData& a, WorldData& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline WorldData* New() const final {
    return CreateMaybeMessage<WorldData>(NULL);
  }

  WorldData* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<WorldData>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const WorldData& from);
  void MergeFrom(const WorldData& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(WorldData* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .protocol.Coord obstacleCoords = 2;
  int obstaclecoords_size() const;
  void clear_obstaclecoords();
  static const int kObstacleCoordsFieldNumber = 2;
  ::protocol::Coord* mutable_obstaclecoords(int index);
  ::google::protobuf::RepeatedPtrField< ::protocol::Coord >*
      mutable_obstaclecoords();
  const ::protocol::Coord& obstaclecoords(int index) const;
  ::protocol::Coord* add_obstaclecoords();
  const ::google::protobuf::RepeatedPtrField< ::protocol::Coord >&
      obstaclecoords() const;

  // .protocol.RobotData robotData = 1;
  bool has_robotdata() const;
  void clear_robotdata();
  static const int kRobotDataFieldNumber = 1;
  private:
  const ::protocol::RobotData& _internal_robotdata() const;
  public:
  const ::protocol::RobotData& robotdata() const;
  ::protocol::RobotData* release_robotdata();
  ::protocol::RobotData* mutable_robotdata();
  void set_allocated_robotdata(::protocol::RobotData* robotdata);

  // .protocol.Coord ballCoord = 3;
  bool has_ballcoord() const;
  void clear_ballcoord();
  static const int kBallCoordFieldNumber = 3;
  private:
  const ::protocol::Coord& _internal_ballcoord() const;
  public:
  const ::protocol::Coord& ballcoord() const;
  ::protocol::Coord* release_ballcoord();
  ::protocol::Coord* mutable_ballcoord();
  void set_allocated_ballcoord(::protocol::Coord* ballcoord);

  // @@protoc_insertion_point(class_scope:protocol.WorldData)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::protocol::Coord > obstaclecoords_;
  ::protocol::RobotData* robotdata_;
  ::protocol::Coord* ballcoord_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_world_5fdata_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Coord

// double x = 1;
inline void Coord::clear_x() {
  x_ = 0;
}
inline double Coord::x() const {
  // @@protoc_insertion_point(field_get:protocol.Coord.x)
  return x_;
}
inline void Coord::set_x(double value) {
  
  x_ = value;
  // @@protoc_insertion_point(field_set:protocol.Coord.x)
}

// double y = 2;
inline void Coord::clear_y() {
  y_ = 0;
}
inline double Coord::y() const {
  // @@protoc_insertion_point(field_get:protocol.Coord.y)
  return y_;
}
inline void Coord::set_y(double value) {
  
  y_ = value;
  // @@protoc_insertion_point(field_set:protocol.Coord.y)
}

// -------------------------------------------------------------------

// Position

// .protocol.Coord coord = 1;
inline bool Position::has_coord() const {
  return this != internal_default_instance() && coord_ != NULL;
}
inline void Position::clear_coord() {
  if (GetArenaNoVirtual() == NULL && coord_ != NULL) {
    delete coord_;
  }
  coord_ = NULL;
}
inline const ::protocol::Coord& Position::_internal_coord() const {
  return *coord_;
}
inline const ::protocol::Coord& Position::coord() const {
  const ::protocol::Coord* p = coord_;
  // @@protoc_insertion_point(field_get:protocol.Position.coord)
  return p != NULL ? *p : *reinterpret_cast<const ::protocol::Coord*>(
      &::protocol::_Coord_default_instance_);
}
inline ::protocol::Coord* Position::release_coord() {
  // @@protoc_insertion_point(field_release:protocol.Position.coord)
  
  ::protocol::Coord* temp = coord_;
  coord_ = NULL;
  return temp;
}
inline ::protocol::Coord* Position::mutable_coord() {
  
  if (coord_ == NULL) {
    auto* p = CreateMaybeMessage<::protocol::Coord>(GetArenaNoVirtual());
    coord_ = p;
  }
  // @@protoc_insertion_point(field_mutable:protocol.Position.coord)
  return coord_;
}
inline void Position::set_allocated_coord(::protocol::Coord* coord) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete coord_;
  }
  if (coord) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      coord = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, coord, submessage_arena);
    }
    
  } else {
    
  }
  coord_ = coord;
  // @@protoc_insertion_point(field_set_allocated:protocol.Position.coord)
}

// double theta = 2;
inline void Position::clear_theta() {
  theta_ = 0;
}
inline double Position::theta() const {
  // @@protoc_insertion_point(field_get:protocol.Position.theta)
  return theta_;
}
inline void Position::set_theta(double value) {
  
  theta_ = value;
  // @@protoc_insertion_point(field_set:protocol.Position.theta)
}

// -------------------------------------------------------------------

// WheelsVelocity

// double leftWheelVelocity = 1;
inline void WheelsVelocity::clear_leftwheelvelocity() {
  leftwheelvelocity_ = 0;
}
inline double WheelsVelocity::leftwheelvelocity() const {
  // @@protoc_insertion_point(field_get:protocol.WheelsVelocity.leftWheelVelocity)
  return leftwheelvelocity_;
}
inline void WheelsVelocity::set_leftwheelvelocity(double value) {
  
  leftwheelvelocity_ = value;
  // @@protoc_insertion_point(field_set:protocol.WheelsVelocity.leftWheelVelocity)
}

// double rightWheelVelocity = 2;
inline void WheelsVelocity::clear_rightwheelvelocity() {
  rightwheelvelocity_ = 0;
}
inline double WheelsVelocity::rightwheelvelocity() const {
  // @@protoc_insertion_point(field_get:protocol.WheelsVelocity.rightWheelVelocity)
  return rightwheelvelocity_;
}
inline void WheelsVelocity::set_rightwheelvelocity(double value) {
  
  rightwheelvelocity_ = value;
  // @@protoc_insertion_point(field_set:protocol.WheelsVelocity.rightWheelVelocity)
}

// -------------------------------------------------------------------

// RobotData

// .protocol.Position position = 1;
inline bool RobotData::has_position() const {
  return this != internal_default_instance() && position_ != NULL;
}
inline void RobotData::clear_position() {
  if (GetArenaNoVirtual() == NULL && position_ != NULL) {
    delete position_;
  }
  position_ = NULL;
}
inline const ::protocol::Position& RobotData::_internal_position() const {
  return *position_;
}
inline const ::protocol::Position& RobotData::position() const {
  const ::protocol::Position* p = position_;
  // @@protoc_insertion_point(field_get:protocol.RobotData.position)
  return p != NULL ? *p : *reinterpret_cast<const ::protocol::Position*>(
      &::protocol::_Position_default_instance_);
}
inline ::protocol::Position* RobotData::release_position() {
  // @@protoc_insertion_point(field_release:protocol.RobotData.position)
  
  ::protocol::Position* temp = position_;
  position_ = NULL;
  return temp;
}
inline ::protocol::Position* RobotData::mutable_position() {
  
  if (position_ == NULL) {
    auto* p = CreateMaybeMessage<::protocol::Position>(GetArenaNoVirtual());
    position_ = p;
  }
  // @@protoc_insertion_point(field_mutable:protocol.RobotData.position)
  return position_;
}
inline void RobotData::set_allocated_position(::protocol::Position* position) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete position_;
  }
  if (position) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      position = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, position, submessage_arena);
    }
    
  } else {
    
  }
  position_ = position;
  // @@protoc_insertion_point(field_set_allocated:protocol.RobotData.position)
}

// .protocol.WheelsVelocity wheelsVelocity = 2;
inline bool RobotData::has_wheelsvelocity() const {
  return this != internal_default_instance() && wheelsvelocity_ != NULL;
}
inline void RobotData::clear_wheelsvelocity() {
  if (GetArenaNoVirtual() == NULL && wheelsvelocity_ != NULL) {
    delete wheelsvelocity_;
  }
  wheelsvelocity_ = NULL;
}
inline const ::protocol::WheelsVelocity& RobotData::_internal_wheelsvelocity() const {
  return *wheelsvelocity_;
}
inline const ::protocol::WheelsVelocity& RobotData::wheelsvelocity() const {
  const ::protocol::WheelsVelocity* p = wheelsvelocity_;
  // @@protoc_insertion_point(field_get:protocol.RobotData.wheelsVelocity)
  return p != NULL ? *p : *reinterpret_cast<const ::protocol::WheelsVelocity*>(
      &::protocol::_WheelsVelocity_default_instance_);
}
inline ::protocol::WheelsVelocity* RobotData::release_wheelsvelocity() {
  // @@protoc_insertion_point(field_release:protocol.RobotData.wheelsVelocity)
  
  ::protocol::WheelsVelocity* temp = wheelsvelocity_;
  wheelsvelocity_ = NULL;
  return temp;
}
inline ::protocol::WheelsVelocity* RobotData::mutable_wheelsvelocity() {
  
  if (wheelsvelocity_ == NULL) {
    auto* p = CreateMaybeMessage<::protocol::WheelsVelocity>(GetArenaNoVirtual());
    wheelsvelocity_ = p;
  }
  // @@protoc_insertion_point(field_mutable:protocol.RobotData.wheelsVelocity)
  return wheelsvelocity_;
}
inline void RobotData::set_allocated_wheelsvelocity(::protocol::WheelsVelocity* wheelsvelocity) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete wheelsvelocity_;
  }
  if (wheelsvelocity) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      wheelsvelocity = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, wheelsvelocity, submessage_arena);
    }
    
  } else {
    
  }
  wheelsvelocity_ = wheelsvelocity;
  // @@protoc_insertion_point(field_set_allocated:protocol.RobotData.wheelsVelocity)
}

// -------------------------------------------------------------------

// WorldData

// .protocol.RobotData robotData = 1;
inline bool WorldData::has_robotdata() const {
  return this != internal_default_instance() && robotdata_ != NULL;
}
inline void WorldData::clear_robotdata() {
  if (GetArenaNoVirtual() == NULL && robotdata_ != NULL) {
    delete robotdata_;
  }
  robotdata_ = NULL;
}
inline const ::protocol::RobotData& WorldData::_internal_robotdata() const {
  return *robotdata_;
}
inline const ::protocol::RobotData& WorldData::robotdata() const {
  const ::protocol::RobotData* p = robotdata_;
  // @@protoc_insertion_point(field_get:protocol.WorldData.robotData)
  return p != NULL ? *p : *reinterpret_cast<const ::protocol::RobotData*>(
      &::protocol::_RobotData_default_instance_);
}
inline ::protocol::RobotData* WorldData::release_robotdata() {
  // @@protoc_insertion_point(field_release:protocol.WorldData.robotData)
  
  ::protocol::RobotData* temp = robotdata_;
  robotdata_ = NULL;
  return temp;
}
inline ::protocol::RobotData* WorldData::mutable_robotdata() {
  
  if (robotdata_ == NULL) {
    auto* p = CreateMaybeMessage<::protocol::RobotData>(GetArenaNoVirtual());
    robotdata_ = p;
  }
  // @@protoc_insertion_point(field_mutable:protocol.WorldData.robotData)
  return robotdata_;
}
inline void WorldData::set_allocated_robotdata(::protocol::RobotData* robotdata) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete robotdata_;
  }
  if (robotdata) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      robotdata = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, robotdata, submessage_arena);
    }
    
  } else {
    
  }
  robotdata_ = robotdata;
  // @@protoc_insertion_point(field_set_allocated:protocol.WorldData.robotData)
}

// repeated .protocol.Coord obstacleCoords = 2;
inline int WorldData::obstaclecoords_size() const {
  return obstaclecoords_.size();
}
inline void WorldData::clear_obstaclecoords() {
  obstaclecoords_.Clear();
}
inline ::protocol::Coord* WorldData::mutable_obstaclecoords(int index) {
  // @@protoc_insertion_point(field_mutable:protocol.WorldData.obstacleCoords)
  return obstaclecoords_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::protocol::Coord >*
WorldData::mutable_obstaclecoords() {
  // @@protoc_insertion_point(field_mutable_list:protocol.WorldData.obstacleCoords)
  return &obstaclecoords_;
}
inline const ::protocol::Coord& WorldData::obstaclecoords(int index) const {
  // @@protoc_insertion_point(field_get:protocol.WorldData.obstacleCoords)
  return obstaclecoords_.Get(index);
}
inline ::protocol::Coord* WorldData::add_obstaclecoords() {
  // @@protoc_insertion_point(field_add:protocol.WorldData.obstacleCoords)
  return obstaclecoords_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::protocol::Coord >&
WorldData::obstaclecoords() const {
  // @@protoc_insertion_point(field_list:protocol.WorldData.obstacleCoords)
  return obstaclecoords_;
}

// .protocol.Coord ballCoord = 3;
inline bool WorldData::has_ballcoord() const {
  return this != internal_default_instance() && ballcoord_ != NULL;
}
inline void WorldData::clear_ballcoord() {
  if (GetArenaNoVirtual() == NULL && ballcoord_ != NULL) {
    delete ballcoord_;
  }
  ballcoord_ = NULL;
}
inline const ::protocol::Coord& WorldData::_internal_ballcoord() const {
  return *ballcoord_;
}
inline const ::protocol::Coord& WorldData::ballcoord() const {
  const ::protocol::Coord* p = ballcoord_;
  // @@protoc_insertion_point(field_get:protocol.WorldData.ballCoord)
  return p != NULL ? *p : *reinterpret_cast<const ::protocol::Coord*>(
      &::protocol::_Coord_default_instance_);
}
inline ::protocol::Coord* WorldData::release_ballcoord() {
  // @@protoc_insertion_point(field_release:protocol.WorldData.ballCoord)
  
  ::protocol::Coord* temp = ballcoord_;
  ballcoord_ = NULL;
  return temp;
}
inline ::protocol::Coord* WorldData::mutable_ballcoord() {
  
  if (ballcoord_ == NULL) {
    auto* p = CreateMaybeMessage<::protocol::Coord>(GetArenaNoVirtual());
    ballcoord_ = p;
  }
  // @@protoc_insertion_point(field_mutable:protocol.WorldData.ballCoord)
  return ballcoord_;
}
inline void WorldData::set_allocated_ballcoord(::protocol::Coord* ballcoord) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete ballcoord_;
  }
  if (ballcoord) {
    ::google::protobuf::Arena* submessage_arena = NULL;
    if (message_arena != submessage_arena) {
      ballcoord = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, ballcoord, submessage_arena);
    }
    
  } else {
    
  }
  ballcoord_ = ballcoord;
  // @@protoc_insertion_point(field_set_allocated:protocol.WorldData.ballCoord)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace protocol

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_world_5fdata_2eproto
