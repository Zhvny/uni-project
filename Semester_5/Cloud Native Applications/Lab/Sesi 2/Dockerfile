# Stage 1 -> Install Dependency + Run Build
# Specify base image
FROM node:22-alpine AS builder

# Set working directory
WORKDIR /app

# Copy package.json and package-lock.json
COPY package*.json ./

# RUN -> Install Dependency
RUN npm ci

# Copy sisa files
COPY . .

# npm run build
RUN npm run build

# Stage 2 -> Serve the build
FROM nginx:alpine AS runner

WORKDIR /usr/share/nginx/html

# Copy <from> <what file> <to where>
COPY --from=builder /app/dist .

# Entrypoint -> dijalankan saat image udah jadi container -> image run
ENTRYPOINT ["nginx", "-g", "daemon off;"]