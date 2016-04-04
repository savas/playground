// Edge

namespace reactive {
namespace graph {

#include "Identity.h"

class EdgeIf: public virtual NodeIf {
public:
	virtual ~EdgeIf() = default;

	virtual future<Identity> getSource() const = 0;
	virtual future<Identity> getPredicate() const = 0;
	virtual future<Identity> getDestination() const = 0;

	virtual future<void> setSource(const Identity&) = 0;
	virtual future<void> setPredicate(const Identity&) = 0;
	virtual future<void> setDestination(const Identity&) = 0;
};

}
}
