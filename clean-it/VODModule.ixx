module;

#include "VODServer.h"

export module VOD;

#include "VODExport.h"

namespace ci
{
	export class Movie;
	export class IVODServer;
	export class ILogWriter;
	export class IMovieObserver;
	export class IStreamer;

    export std::shared_ptr<IVODServer> VODEXPORT CreateVODServer(std::shared_ptr<IStreamer> streamer, std::shared_ptr<ILogWriter> logWriter);
}