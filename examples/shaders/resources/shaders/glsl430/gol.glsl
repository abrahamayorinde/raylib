// Game of Life logic shader
#version 430

#define GOL_WIDTH 768

layout (local_size_x = 16, local_size_y = 16, local_size_x = 1) in;

layout(std430, binding = 1) readonly restrict buffer golLayout {
  uint golBuffer[]; // golBuffer[x, y] = golBuffer[x + gl_NumWorkGroups.x * y]
};

layout(std430, set = 1, binding = 2) writeonly restrict buffer golLayout2 {
  uint golBufferDest[]; // golBufferDest[x, y] = golBufferDest[x + gl_NumWorkGroups.x * y]
};

#define fetchGol(x, y) ((((x) < 0) || ((y) < 0) || ((x) > GOL_WIDTH) || ((y) > GOL_WIDTH)) \
  ? (0) \
  : golBuffer[(x) + GOL_WIDTH * (y)])

#define setGol(x, y, value) golBufferDest[(x) + GOL_WIDTH * (y)] = value

void main()
{
  uint neighbour_count = 0;
  uint x = gl_GlobalInvocationID.x;
  uint y = gl_GlobalInvocationID.y;

  // Top left
  neighbour_count += fetchGol(x - 1, y - 1);
  
  // Top middle
  neighbour_count += fetchGol(x, y - 1);
  
  // Top right
  neighbour_count += fetchGol(x + 1, y - 1);
  
  // Left
  neighbour_count += fetchGol(x - 1, y);

  // Right
  neighbour_count += fetchGol(x + 1, y);
  
  // Bottom left
  neighbour_count += fetchGol(x - 1, y + 1);
  
  // Bottom middle
  neighbour_count += fetchGol(x, y + 1);
  
  // Bottom right
  neighbour_count += fetchGol(x + 1, y + 1);

  if (neighbour_count == 3)
    setGol(x, y, 1);
  else if (neighbour_count == 2)
    setGol(x, y, fetchGol(x, y));
  else
    setGol(x, y, 0);
}