var cacheName = 'saltb0rn-blog';
var shellFiles = [
    '/docs/index.html',
    '/docs/js/main.js',
    '/docs/css/index.css',
    '/docs/css/stylesheet.css',
    '/docs/css/animation.css',
    '/docs/css/tags.css',
    '/docs/img/logo.png',
];

self.addEventListener('install', function(e) {
    console.log('[Service Worker] Install');
    e.waitUntil(
        caches.open(cacheName).then(function(cache) {
            console.log('[Service Work] Caching app shell');
            return cache.addAll(shellFiles);
        })
    );
});

self.addEventListener('fetch', function(e) {
    e.respondWith(
        caches.match(e.request).then(function(r) {
            console.log('[Service Worker] Fetching resourse: ' + e.request.url);
            return r || fetch(e.request).then(function(response) {
                return caches.open(cacheName).then(function(cache) {
                    console.log('[Service Worker] Caching new resourse: ' + e.request.url);
                    cache.put(e.request, response.clone());
                    return response;
                });
            });
        })
    );
});
