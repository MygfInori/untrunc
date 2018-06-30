#ifndef NAL_H
#define NAL_H

#include <cstdint>
#include <vector>

#include "common.h"

class NalInfo {
public:
	NalInfo() = default;
	NalInfo(const uchar* start, int max_size);
	NalInfo(NalInfo const& other);
	~NalInfo();
	NalInfo& operator= ( NalInfo&& );
//	NalInfo & operator= (const NalInfo& other);
//	Foo (const Foo& other);


	int length_ = 0;
	int ref_idc_ = 0;
	int nal_type_ = 0;

	bool is_ok;  // did parsing work
	bool is_forbidden_set_;
	uchar* payload_ = NULL;
	bool parseNal(const uchar* start, uint32_t max_size);
//private:
//	std::vector<uchar> data_;
};


#endif // NAL_H
