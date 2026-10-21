import { useState } from 'react'

export default function App() {
  const [count, setCount] = useState(0)

  return (
    <main style={{ fontFamily: 'system-ui', padding: '2rem' }}>
      <h1>Sesi 1: Azure App Service</h1>
      <p>Halaman statis hasil build Vite, disajikan lewat container nginx.</p>
      <button onClick={() => setCount((c) => c + 1)}>Klik: {count}</button>
    </main>
  )
}
