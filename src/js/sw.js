var cacheName = 'saltb0rn-blog';
var shellFiles = [
    '../index.html',
    'main.js',
    'live.js',
    '../css/index.css',
    '../css/stylesheet.css',
    '../css/animation.css',
    '../css/tags.css',
    '../img/logo.png',
];

self.addEventListener('install', function(e) {
    console.log('[Service Worker] Install');
    e.waitUntil(
        window.self.caches.open(cacheName).then(function(cache) {
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
